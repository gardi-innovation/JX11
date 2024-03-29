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
    
    SliderAttachment typeAttachment1 { audioProcessor.apvts, ParameterID::type.getParamID(), typeKnob.slider };
    SliderAttachment toneAttachment1 { audioProcessor.apvts, ParameterID::tone.getParamID(), toneKnob.slider };
    SliderAttachment shapeAttachment1 { audioProcessor.apvts, ParameterID::shape.getParamID(), shapeKnob.slider };
    SliderAttachment styleAttachment1 { audioProcessor.apvts, ParameterID::style.getParamID(), styleKnob.slider };
    
    juce::TextButton polyModeButton;
    juce::TextButton glideModeButton;
    juce::TextButton surpriseModeButton;
    juce::TextButton pitchModeButton;
    using ButtonAttachment = APVTS::ButtonAttachment;
    ButtonAttachment polyModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), polyModeButton };
    ButtonAttachment glideModeAttachment { audioProcessor.apvts, ParameterID::glideMode.getParamID(), glideModeButton };
    ButtonAttachment surpriseModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), surpriseModeButton };
    ButtonAttachment pitchModeAttachment { audioProcessor.apvts, ParameterID::pitchMode.getParamID(), pitchModeButton };
    
    juce::Slider outputFader;
    SliderAttachment outputFaderAttachment { audioProcessor.apvts, ParameterID::outputLevel.getParamID(), outputFader };
    
    LookAndFeel globalLNF;
    
    juce::TextButton midiLearnButton;
    
    void timerCallback() override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JX11AudioProcessorEditor)
};
