/*
  ==============================================================================

    Synth.cpp
    Created: 30 Dec 2023 3:32:16pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#include "Synth.h"

Synth::Synth()
{
    sampleRate = 44100.0f;
}

void Synth::allocateResources(double sampleRate_, int /*samplesPerBlock*/)
{
    sampleRate = static_cast<float>(sampleRate_);
}

void Synth::deallocateResources()
{
    // do nothing
}

void Synth::reset()
{
    // do nothing yet
}

void Synth::render(float **outputBuffers, int sampleCount)
{
    // do nothing yet
}

void Synth::midiMessage(uint8_t data0, uint8_t data1, uint8_t data2)
{
    // do nothing yet
}
