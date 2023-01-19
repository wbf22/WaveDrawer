/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "DrawWindow.h"

//==============================================================================
/**
*/
class WaveDrawerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WaveDrawerAudioProcessorEditor (WaveDrawerAudioProcessor&);
    ~WaveDrawerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseDown(const juce::MouseEvent &event) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WaveDrawerAudioProcessor& audioProcessor;
    DrawWindow drawWindow;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveDrawerAudioProcessorEditor)
};
