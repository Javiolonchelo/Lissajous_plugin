#include "PluginEditor.h"

#include "PluginProcessor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p) {
    juce::ignoreUnused(processorRef);

	mainWindowWidth = 600;
	mainWindowHeight = int(mainWindowWidth * 9 / 16);

	DVD_asset = juce::ImageCache::getFromMemory(BinaryData::dvd_png, BinaryData::dvd_pngSize);
	DVD_width = 111;
	DVD_height = 50;
	DVD_position = juce::Point<int>(rand() % (mainWindowWidth - DVD_width), rand() % (mainWindowHeight - DVD_height));
	directionPositive[0] = true;
	directionPositive[1] = true;
	startTimer(int(1000 / 60));
	setSize(mainWindowWidth, mainWindowHeight);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
	g.drawImage(DVD_asset, DVD_position.getX(), DVD_position.getY(), DVD_width, DVD_height, 0, 0, DVD_asset.getWidth(), DVD_asset.getHeight());
}

void AudioPluginAudioProcessorEditor::resized() {}
