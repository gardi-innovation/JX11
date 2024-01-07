/*
  ==============================================================================

    Envelope.h
    Created: 7 Jan 2024 9:31:03pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

const float SILENCE = 0.0001f;

class Envelope
{
public:
    float nextValue()
    {
        level = multiplier * (level - target) + target;
        
        if(level + target > 3.0f){
            multiplier = decayMultiplier;
            target = sustainLevel;
        }
            
        return level;
    }
    
    void reset()
    {
        level = 0.0f;
        target = 0.0f;
        multiplier = 0.0f;
    }
    
    void release()
    {
        target = 0.0f;
        multiplier = releaseMultiplier;
    }
    
    inline bool isActive() const
    {
        return level > SILENCE;
    }
    
    inline bool isAinAttack() const
    {
        return target >= 2.0f;
    }
    
    void attack()
    {
        level += SILENCE + SILENCE;
        target = 2.0f;
        multiplier = attackMultiplier;
    }
    
    float level;
    
    float attackMultiplier;
    float decayMultiplier;
    float sustainLevel;
    float releaseMultiplier;
    
private:
    float multiplier;
    float target;
};
