/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
WaveDrawerAudioProcessorEditor::WaveDrawerAudioProcessorEditor (WaveDrawerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), drawWindow()
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1000, 600);
    addAndMakeVisible(drawWindow);
}

WaveDrawerAudioProcessorEditor::~WaveDrawerAudioProcessorEditor()
{
}

//==============================================================================
void WaveDrawerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.drawText(audioProcessor.debug, 0, 290, 380, 20, juce::Justification::bottomLeft);
}




void WaveDrawerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    drawWindow.setBounds(450, 50, 400, 300);
}

void WaveDrawerAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{
    repaint();
}



