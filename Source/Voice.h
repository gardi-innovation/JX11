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
    
    void reset()
    {
        note = 0;
        //velocity = 0;
        osc.reset();
    }
    
    float render()
    {
        return osc.nextSample();
    }
};
