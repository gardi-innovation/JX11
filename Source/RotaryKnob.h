/*
  ==============================================================================

    RotaryKnob.h
    Created: 12 Feb 2024 9:02:48pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RotaryKnob  : public juce::Component
{
public:
    RotaryKnob();
    ~RotaryKnob() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    juce::Slider slider;
    juce::String label;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RotaryKnob)
};
