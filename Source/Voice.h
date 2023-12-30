/*
  ==============================================================================

    Voice.h
    Created: 30 Dec 2023 3:32:26pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

struct Voice
{
    int note;
    int velocity;
    
    void reset()
    {
        note = 0;
        velocity = 0;
    }
};
