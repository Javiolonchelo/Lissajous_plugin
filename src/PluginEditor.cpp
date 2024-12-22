#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor& p)
    : juce::AudioProcessorEditor(p), processorRef(p) {
    mainWindowWidth  = 600;
    mainWindowHeight = int(mainWindowWidth * 9 / 16);

    previousPos = juce::Point<float>(mainWindowWidth / 2, mainWindowHeight / 2);
    currentPos  = juce::Point<float>(mainWindowWidth / 2, mainWindowHeight / 2);

    logoPosition = juce::Point<int>(rand() % (mainWindowWidth - logoWidth), rand() % (mainWindowHeight - logoHeight));

    stepSize = 5;
    jassert(stepSize < std::min(mainWindowWidth, mainWindowHeight) / 3);  // This ensures the logo doesn't move in a
                                                                          // weird way

    bypassButton.setButtonText("Bypass");
    bypassButton.setBounds(10, 10, 200, 30);
    addAndMakeVisible(&bypassButton);

    // Set up attachment for the bypass button
    bypassAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(
        p.apvts, params::bypass.getParamID(), bypassButton);

    startTimer(int(1000 / 60));
    setSize(mainWindowWidth, mainWindowHeight);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    if (processorRef.apvts.getParameterAsValue(params::bypass.getParamID()) == 1.0f) {
        g.drawImage(logoAsset, logoPosition.getX(), logoPosition.getY(), logoWidth, logoHeight, 0, 0,
                    logoAsset.getWidth(), logoAsset.getHeight());
    } else {
        g.setColour(juce::Colours::white);
        g.setFont(25.0f);
        g.drawFittedText("Bypass Off, should be drawing lines rn...", getLocalBounds(), juce::Justification::centred,
                         1);
        g.setColour(juce::Colours::green);

        previousPos.setXY(currentPos.getX(), currentPos.getY());

        auto x       = processorRef.apvts.getParameter(params::beam_x.getParamID())->getValue() / 2;
        auto y       = processorRef.apvts.getParameter(params::beam_y.getParamID())->getValue() / 2;
        auto oscSize = std::min(mainWindowWidth, mainWindowHeight);

        x = oscSize / 2 + x * oscSize;
        y = oscSize / 2 + y * oscSize;

        currentPos.setXY(x, y);

        juce::Line<float> l(previousPos, currentPos);
        juce::Path        p;
        p.addLineSegment(l, 4.0f);
        g.fillPath(p);

        previousPos.setXY(currentPos.getX(), currentPos.getY());
    }
}

void AudioPluginAudioProcessorEditor::resized() {}
