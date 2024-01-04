/*
  ==============================================================================

    Voice.h
    Created: 30 Dec 2023 3:32:26pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"

struct Voice
{
    int note;
    //int velocity;
    Oscillator osc;
    float saw;
    
    void reset()
    {
        note = 0;
        //velocity = 0;
        saw = 0.0f;
        osc.reset();
    }
    
    float render()
    {
        float sample = osc.nextSample();
        saw = saw * 0.997f - sample;
        return saw;
    }
};
