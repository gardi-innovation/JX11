/*
  ==============================================================================

    Voice.h
    Created: 30 Dec 2023 3:32:26pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"
#include "Envelope.h"

struct Voice
{
    int note;
    //int velocity;
    Oscillator osc;
    float saw;
    
    Envelope env;
    
    void reset()
    {
        note = 0;
        //velocity = 0;
        saw = 0.0f;
        osc.reset();
        env.reset();
    }
    
    float render(float input)
    {
        float sample = osc.nextSample();
        saw = saw * 0.997f - sample;
        
        float output = saw + input;
        
        float envelope = env.nextValue();
        return output * envelope;
    }
    
    void releae()
    {
        env.release();
    }
};
