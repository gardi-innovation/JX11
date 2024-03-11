/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "RotaryKnob.h"
#include "LookAndFeel.h"

//==============================================================================
/**
*/
class JX11AudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Button::Listener, private juce::Timer
{
public:
    JX11AudioProcessorEditor (JX11AudioProcessor&);
    ~JX11AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void buttonClicked(juce::Button* button) override;
    JX11AudioProcessor& audioProcessor;
    RotaryKnob typeKnob;
    RotaryKnob toneKnob;
    RotaryKnob shapeKnob;
    RotaryKnob styleKnob;
    
    using APVTS = juce::AudioProcessorValueTreeState;
    using SliderAttachment = APVTS::SliderAttachment;
    SliderAttachment outputLevelAttachment { audioProcessor.apvts, ParameterID::outputLevel.getParamID(), typeKnob.slider };
    SliderAttachment filterResoAttachment { audioProcessor.apvts, ParameterID::filterReso.getParamID(), toneKnob.slider };
    SliderAttachment shapeAttachment { audioProcessor.apvts, ParameterID::filterReso.getParamID(), shapeKnob.slider };
    SliderAttachment styleAttachment { audioProcessor.apvts, ParameterID::filterReso.getParamID(), styleKnob.slider };
    
    juce::TextButton polyModeButton;
    juce::TextButton glideModeButton;
    juce::TextButton surpriseModeButton;
    juce::TextButton bypassModeButton;
    using ButtonAttachment = APVTS::ButtonAttachment;
    ButtonAttachment polyModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), polyModeButton };
    ButtonAttachment glideModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), glideModeButton };
    ButtonAttachment surpriseModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), surpriseModeButton };
    ButtonAttachment bypassModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), bypassModeButton };
    
    LookAndFeel globalLNF;
    
    juce::TextButton midiLearnButton;
    
    void timerCallback() override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JX11AudioProcessorEditor)
};
