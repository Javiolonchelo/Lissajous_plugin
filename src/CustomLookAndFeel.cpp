//  Studio 2024 - All rights reserved

#include "CustomLookAndFeel.h"
#include <JuceHeader.h>

using namespace juce;

CustomLookAndFeel::CustomLookAndFeel()
{
    setColour(RoundedMeter::backgroundColourId, DBobsColours::background);
    setColour(RoundedMeter::lowLevelId, DBobsColours::paletPurple);
    setColour(RoundedMeter::midLevelId, DBobsColours::paletBlue);
    setColour(RoundedMeter::highLevelId, DBobsColours::paletGold);
    setColour(RoundedMeter::textColourId, DBobsColours::paletWhite);
    setColour(RoundedMeter::tickMarkColourId, DBobsColours::darkGrey);

    coldAndHot.addColour(0.0, DBobsColours::paletViolet);
    coldAndHot.addColour(1.0, DBobsColours::paletHotiolet);
}

CustomLookAndFeel::~CustomLookAndFeel() {}

void CustomLookAndFeel::drawLabel(Graphics& g, Label& label)
{
    g.setColour(Colours::white);
    //g.setFont(UltraFunnyFont.withHeight(globalFontSize));
    g.drawFittedText(label.getText(), label.getLocalBounds(), Justification::centred, 1);
}

const Font& CustomLookAndFeel::getFont() { return StandardFont; }
const int& CustomLookAndFeel::getFontSize() { return globalFontSize; }
Font        CustomLookAndFeel::getAlertWindowFont() { return StandardFont; }
Font        CustomLookAndFeel::getAlertWindowMessageFont() { return FunnyFont; }

//void CustomLookAndFeel::drawRotarySlider(){
//
//}
