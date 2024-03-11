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
    typeKnob.label = "Type";
    addAndMakeVisible(typeKnob);

    toneKnob.label = "Tone";
    addAndMakeVisible(toneKnob);
    
    shapeKnob.label = "Shape";
    addAndMakeVisible(shapeKnob);
    
    styleKnob.label = "Style";
    addAndMakeVisible(styleKnob);
    
    polyModeButton.setButtonText("Poly");
    polyModeButton.setClickingTogglesState(true);
    addAndMakeVisible(polyModeButton);
    
    glideModeButton.setButtonText("Glide");
    glideModeButton.setClickingTogglesState(true);
    addAndMakeVisible(glideModeButton);
    
    surpriseModeButton.setButtonText("Surprise");
    surpriseModeButton.setClickingTogglesState(true);
    addAndMakeVisible(surpriseModeButton);
    
    bypassModeButton.setButtonText("Bypass");
    bypassModeButton.setClickingTogglesState(true);
    addAndMakeVisible(bypassModeButton);
    
    juce::LookAndFeel::setDefaultLookAndFeel(&globalLNF);
    
    //midiLearnButton.setButtonText("MIDI Learn");
    //midiLearnButton.addListener(this);
    //addAndMakeVisible(midiLearnButton);
    
    auto imageFull = juce::ImageCache::getFromMemory(BinaryData::CloseupFrontviewWhitefacadeofdirtyindustrialmetalTheentirecenteriswhite_jpg, BinaryData::CloseupFrontviewWhitefacadeofdirtyindustrialmetalTheentirecenteriswhite_jpgSize);
    
    auto imageScaled = imageFull.rescaled(imageFull.getWidth()*(0.3), imageFull.getHeight()*(0.3));
    DBG(imageFull.getWidth());
    DBG(imageFull.getHeight());
    DBG(imageScaled.getWidth());
    DBG(imageScaled.getHeight());
    
    setSize (imageScaled.getWidth(),imageScaled.getHeight());
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
    //auto image = juce::ImageCache::getFromMemory(BinaryData::Logo_png, BinaryData::Logo_pngSize);
    auto imageFull = juce::ImageCache::getFromMemory(BinaryData::CloseupFrontviewWhitefacadeofdirtyindustrialmetalTheentirecenteriswhite_jpg, BinaryData::CloseupFrontviewWhitefacadeofdirtyindustrialmetalTheentirecenteriswhite_jpgSize);
    
    auto imageScaled = imageFull.rescaled(imageFull.getWidth()*(0.3), imageFull.getHeight()*0.3);
    
    DBG(imageFull.getWidth());
    DBG(imageFull.getHeight());
    DBG(imageScaled.getWidth());
    DBG(imageScaled.getHeight());
    
    g.drawImage(imageScaled, 0, 0, imageScaled.getWidth(), imageScaled.getHeight(), 0, 0, imageScaled.getWidth(), imageScaled.getHeight());
}

void JX11AudioProcessorEditor::resized()
{
    //outputLevelKnob.setBounds(20, 20, 100, 120);
    //filterResoKnob.setBounds(120, 20, 100, 120);
    //polyModeButton.setBounds(240, 20, 80, 30);
    
    juce::Rectangle rTypeKnob(20, 100, 100, 120);
    typeKnob.setBounds(rTypeKnob);
    
    juce::Rectangle rToneKnob = rTypeKnob.withX(rTypeKnob.getRight() + 20);
    toneKnob.setBounds(rToneKnob);
    
    juce::Rectangle rShapeKnob = rToneKnob.withX(rToneKnob.getRight() + 20);
    shapeKnob.setBounds(rShapeKnob);
    
    juce::Rectangle rStyleKnob = rShapeKnob.withX(rShapeKnob.getRight() + 20);
    styleKnob.setBounds(rStyleKnob);
    
    polyModeButton.setSize(80, 30);
    polyModeButton.setCentrePosition({rTypeKnob.getCentreX(), rTypeKnob.getCentreY() - 100});
    
    glideModeButton.setSize(80, 30);
    glideModeButton.setCentrePosition(rToneKnob.getCentreX(), rToneKnob.getCentreY() - 100);
    
    surpriseModeButton.setSize(80, 30);
    surpriseModeButton.setCentrePosition(rShapeKnob.getCentreX(), rShapeKnob.getCentreY() - 100);
    
    bypassModeButton.setSize(80, 30);
    bypassModeButton.setCentrePosition(rStyleKnob.getCentreX(), rStyleKnob.getCentreY() - 100);
    
    //midiLearnButton.setBounds(400, 20, 100, 30);
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
