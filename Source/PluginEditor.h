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
    //SliderAttachment typeAttachment2 { audioProcessor.apvts, ParameterID::oscFine.getParamID(), typeKnob.slider };
    //SliderAttachment typeAttachment3 { audioProcessor.apvts, ParameterID::oscMix.getParamID(), typeKnob.slider };
    //SliderAttachment typeAttachment4 { audioProcessor.apvts, ParameterID::glideRate.getParamID(), typeKnob.slider };
    //SliderAttachment typeAttachment5 { audioProcessor.apvts, ParameterID::glideBend.getParamID(), typeKnob.slider };
    
    SliderAttachment toneAttachment1 { audioProcessor.apvts, ParameterID::filterFreq.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment2 { audioProcessor.apvts, ParameterID::filterReso.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment3 { audioProcessor.apvts, ParameterID::filterEnv.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment4 { audioProcessor.apvts, ParameterID::filterLFO.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment5 { audioProcessor.apvts, ParameterID::filterVelocity.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment6 { audioProcessor.apvts, ParameterID::filterAttack.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment7 { audioProcessor.apvts, ParameterID::filterDecay.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment8 { audioProcessor.apvts, ParameterID::filterSustain.getParamID(), toneKnob.slider };
    SliderAttachment toneAttachment9 { audioProcessor.apvts, ParameterID::filterRelease.getParamID(), toneKnob.slider };
    
    SliderAttachment shapeAttachment1 { audioProcessor.apvts, ParameterID::envAttack.getParamID(), shapeKnob.slider };
    SliderAttachment shapeAttachment2 { audioProcessor.apvts, ParameterID::envDecay.getParamID(), shapeKnob.slider };
    SliderAttachment shapeAttachment3 { audioProcessor.apvts, ParameterID::envSustain.getParamID(), shapeKnob.slider };
    SliderAttachment shapeAttachment4 { audioProcessor.apvts, ParameterID::envRelease.getParamID(), shapeKnob.slider };
    
    SliderAttachment styleAttachment1 { audioProcessor.apvts, ParameterID::lfoRate.getParamID(), styleKnob.slider };
    SliderAttachment styleAttachment2 { audioProcessor.apvts, ParameterID::vibrato.getParamID(), styleKnob.slider };
    SliderAttachment styleAttachment3 { audioProcessor.apvts, ParameterID::noise.getParamID(), styleKnob.slider };
    SliderAttachment styleAttachment4 { audioProcessor.apvts, ParameterID::octave.getParamID(), styleKnob.slider };
    SliderAttachment styleAttachment5 { audioProcessor.apvts, ParameterID::tuning.getParamID(), styleKnob.slider };
    
    juce::TextButton polyModeButton;
    juce::TextButton glideModeButton;
    juce::TextButton surpriseModeButton;
    juce::TextButton bypassModeButton;
    using ButtonAttachment = APVTS::ButtonAttachment;
    ButtonAttachment polyModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), polyModeButton };
    ButtonAttachment glideModeAttachment { audioProcessor.apvts, ParameterID::glideMode.getParamID(), glideModeButton };
    ButtonAttachment surpriseModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), surpriseModeButton };
    ButtonAttachment bypassModeAttachment { audioProcessor.apvts, ParameterID::polyMode.getParamID(), bypassModeButton };
    
    LookAndFeel globalLNF;
    
    juce::TextButton midiLearnButton;
    
    void timerCallback() override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JX11AudioProcessorEditor)
};
