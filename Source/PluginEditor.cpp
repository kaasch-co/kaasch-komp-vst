/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "juce_gui_basics/juce_gui_basics.h"
#include "PluginEditor.h"
#include "EditorUtils.h"
//==============================================================================
VstpluginbaseAudioProcessorEditor::VstpluginbaseAudioProcessorEditor(VstpluginbaseAudioProcessor&
		p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);
	
	// Editor controls
	addAndMakeVisible(inputGainSlider);
	addAndMakeVisible(thresholdSlider);
	addAndMakeVisible(outputGainSlider);
	addAndMakeVisible(attackTimeSlider);
	addAndMakeVisible(releaseTimeSlider); 
}

VstpluginbaseAudioProcessorEditor::~VstpluginbaseAudioProcessorEditor()
{
}

//==============================================================================
void VstpluginbaseAudioProcessorEditor::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Passthrough gain test", getLocalBounds(), juce::Justification::topLeft, 1);
}

void VstpluginbaseAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
	inputGainSlider.setBounds(40, 30, 20, getHeight() - 60);
	thresholdSlider.setBounds(120, 30, 20, getHeight() - 60);
	outputGainSlider.setBounds(getWidth() - 80, 30, 20, getHeight() - 60);
	attackTimeSlider.setBounds(80, 30, 20, getHeight() - 60);
	releaseTimeSlider.setBounds(getWidth() - 120, 30, 20, getHeight() - 60);

}
