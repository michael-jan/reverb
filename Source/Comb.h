/*
  ==============================================================================

    Comb.h
    Created: 14 Nov 2021 4:39:21pm
    Author:  Michael Jan

  ==============================================================================
*/

#include <vector>

#pragma once

class Comb {
public:
    Comb(float delay = 5000, float decay = 0.5);
    void reset();
    float process(float sample);
    
    int getDelay();
    void setDelay(int newDelay);
private:
    std::vector<float> buf;
    int bufidx, delay;
    float decay;
};

inline float Comb::process(float sample)
{
    auto n = buf.size();
    float output = sample + decay * buf[(bufidx - delay) % n];
    
    buf[bufidx] = output;
    if (++bufidx == n)
        bufidx = 0;
    
    return output;
}
