/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ReverbAudioProcessorEditor::ReverbAudioProcessorEditor (ReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    delaySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    delaySlider.setSliderSnapsToMousePosition(false);
    delaySlider.setMouseDragSensitivity(350);
    delaySlider.setColour(juce::Slider::trackColourId, juce::Colours::transparentBlack);
    
    addAndMakeVisible(delaySlider);
    
    delayAttachment.reset(new SliderAttachment(p.getParams(), "DELAY", delaySlider));
    
    setSize (200, 200);
}

ReverbAudioProcessorEditor::~ReverbAudioProcessorEditor()
{
}

//==============================================================================
void ReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void ReverbAudioProcessorEditor::resized()
{
    delaySlider.setBounds(getLocalBounds());
}
