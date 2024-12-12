#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor, private juce::Timer {
   public:
    explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

   private:
    AudioPluginAudioProcessor& processorRef;

    // Assets
    juce::Image DVD_asset;
	int mainWindowWidth, mainWindowHeight, DVD_width, DVD_height;
	juce::Point<int> DVD_position;
	bool directionPositive[2];

    // Timer callback
    void timerCallback() final {
		DVD_position += juce::Point<int>(directionPositive[0] ? 1 : -1, directionPositive[1] ? 1 : -1);
		if (DVD_position.getX() > getWidth() - DVD_width || DVD_position.getX() < 0) {
			directionPositive[0] = !directionPositive[0];
		}
		if (DVD_position.getY() > getHeight() - DVD_height || DVD_position.getY() < 0) {
			directionPositive[1] = !directionPositive[1];
		}
		repaint();
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
