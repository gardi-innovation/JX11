/*
  ==============================================================================

    FilterLadder.h
    Created: 2 Feb 2024 8:50:51pm
    Author:  Edmund í Garði

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class FilterLadder : public juce::dsp::LadderFilter<float>
{
public:
    void updateCoefficients(float cutoff, float Q)
    {
        setCutoffFrequencyHz(cutoff);
        setResonance(std::clamp(Q / 30.0f, 0.0f, 1.0f));
    }
    
    float render(float x)
    {
        updateSmoothers();
        return processSample(x,0);
    }
};
