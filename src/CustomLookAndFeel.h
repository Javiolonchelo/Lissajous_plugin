// dBob Studio 2024     
// 
// Hao Feng Chen Fu     
// Javier Rodrigo López

#pragma once

#include <JuceHeader.h>
#include "CustomColours.h"
//#include "melatonin_blur.h"

using namespace juce;

class CustomLookAndFeel : public LookAndFeel_V4
{
public:
    CustomLookAndFeel();
    ~CustomLookAndFeel() override;

    void drawLabel(Graphics&, Label&) override;
    Font getAlertWindowFont() override;
    Font getAlertWindowMessageFont() override;
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width,
        int height, float sliderPos,
        const float rotaryStartAngle,
        const float rotaryEndAngle, juce::Slider&) override;

    const Font& getFont();
    const int& getFontSize();

private:
    const float    globalFontSize = 20.0f;
    //const Font     standardFont = Font(Typeface::createSystemTypefaceFor(BinaryData::HankenGrotesk_ttf, BinaryData::HankenGrotesk_ttfSize));
    //const Font     funnyFont = Font(Typeface::createSystemTypefaceFor(BinaryData::JuicyFills_ttf, BinaryData::JuicyFills_ttfSize));
    //const Font     ultraFunnyFont = Font("Montserrat", "SemiBold", 2 * globalFontSize);
    ColourGradient coldAndHot;
};