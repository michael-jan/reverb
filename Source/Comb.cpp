/*
  ==============================================================================

    Comb.cpp
    Created: 14 Nov 2021 4:39:21pm
    Author:  Michael Jan

  ==============================================================================
*/

#include "Comb.h"

Comb::Comb(float delay, float decay)
    : buf(1000000)
    , delay(delay)
    , decay(decay)
{
    reset();
}

void Comb::reset()
{
    std::fill(buf.begin(), buf.end(), 0);
    bufidx = 0;
}

int Comb::getDelay() { return delay; }
void Comb::setDelay(int newDelay) { delay = newDelay; }
