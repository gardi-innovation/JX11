/*
  ==============================================================================

    Synth.h
    Created: 30 Dec 2023 3:31:57pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth
{
public:
    Synth();
    
    void allocateResources(double sampleRate, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);
    
    float noiseMix;
    
    float envAttack;
    float envDecay;
    float envSustain;
    float envRelease;
    
    float oscMix;
    
    float detune;
    float tune;
    
    static constexpr int MAX_VOICES = 8;
    int numVoices;
    
private:
    void noteOn(int note, int velocity);
    void noteOff(int note);
    float calcPeriod(int v, int note) const;
    void startVoice(int v, int note, int velocity);
    int findFreeVoice() const;
    
    float sampleRate;
    //Voice voice;
    NoiseGenerator noiseGen;
    
    float pitchBend;
    
    std::array<Voice, MAX_VOICES> voices;
};
