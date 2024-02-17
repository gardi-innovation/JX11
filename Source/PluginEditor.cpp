/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JX11AudioProcessorEditor::JX11AudioProcessorEditor (JX11AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    outputLevelKnob.label = "Level";
    addAndMakeVisible(outputLevelKnob);

    filterResoKnob.label = "Reso";
    addAndMakeVisible(filterResoKnob);
    
    polyModeButton.setButtonText("Poly");
    polyModeButton.setClickingTogglesState(true);
    addAndMakeVisible(polyModeButton);
    
    juce::LookAndFeel::setDefaultLookAndFeel(&globalLNF);
    
    midiLearnButton.setButtonText("MIDI Learn");
    midiLearnButton.addListener(this);
    addAndMakeVisible(midiLearnButton);
    
    setSize (600, 400);
}

JX11AudioProcessorEditor::~JX11AudioProcessorEditor()
{
    midiLearnButton.removeListener(this);
    audioProcessor.midiLearn = false;
}

//==============================================================================
void JX11AudioProcessorEditor::paint (juce::Graphics& g)
{
    //g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    auto image = juce::ImageCache::getFromMemory(BinaryData::Logo_png, BinaryData::Logo_pngSize);
    g.drawImage(image, 0, 0, image.getWidth(), image.getHeight(), 0, 0, image.getWidth(), image.getWidth());
}

void JX11AudioProcessorEditor::resized()
{
    //outputLevelKnob.setBounds(20, 20, 100, 120);
    //filterResoKnob.setBounds(120, 20, 100, 120);
    //polyModeButton.setBounds(240, 20, 80, 30);
    
    juce::Rectangle r(20, 20, 200, 220);
    outputLevelKnob.setBounds(r);
    
    r = r.withX(r.getRight() + 20);
    filterResoKnob.setBounds(r);
    
    polyModeButton.setSize(80, 30);
    polyModeButton.setCentrePosition(r.withX(r.getRight()).getCentre());
    
    midiLearnButton.setBounds(400, 20, 100, 30);
}

void JX11AudioProcessorEditor::buttonClicked(juce::Button* button)
{
    DBG("button clicked");
    button->setButtonText("Waiting...");
    button->setEnabled(false);
    audioProcessor.midiLearn = true;
    startTimer(10);
}

void JX11AudioProcessorEditor::timerCallback()
{
    if (!audioProcessor.midiLearn){
        stopTimer();
        midiLearnButton.setButtonText("MIDI Learn");
        midiLearnButton.setEnabled(true);
    }
}
