#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor, private juce::Timer {
   public:
    AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

   private:
    AudioPluginAudioProcessor& processorRef;

    // Buttons
    juce::ToggleButton bypassButton;

    // Attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> bypassAttachment;

    // Assets
    int              logoWidth{111}, logoHeight{50};
    juce::Image      logoAsset{juce::ImageCache::getFromMemory(BinaryData::dvd_png, BinaryData::dvd_pngSize)};
    juce::Point<int> logoPosition{0, 0};
    bool             direction[2]{true, true};
    int              stepSize{1};

    // Main window
    int mainWindowWidth, mainWindowHeight;

    // Beam
    juce::Point<float> previousPos, currentPos;

    // Timer callback
    void timerCallback() final {
        if (processorRef.apvts.getParameterAsValue(params::bypass.getParamID()) == 0.0f) {
            repaint();
        } else {
            auto deltaX = direction[0] ? stepSize : -stepSize;
            auto deltaY = direction[1] ? stepSize : -stepSize;
            logoPosition += juce::Point<int>(deltaX, deltaY);

            auto limitX = getWidth() - logoWidth;
            auto limitY = getHeight() - logoHeight;

            if (logoPosition.getX() > limitX || logoPosition.getX() < 0) { direction[0] = !direction[0]; }
            if (logoPosition.getY() > limitY || logoPosition.getY() < 0) { direction[1] = !direction[1]; }
            repaint();
        }
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
