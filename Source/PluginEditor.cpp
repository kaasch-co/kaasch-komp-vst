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
	
	// Set default values for editor controls
	inputGainSlider.setValue(0.f);
	thresholdSlider.setValue(0.f);
	outputGainSlider.setValue(0.f);

	attackTimeSlider.setValue(20.f);
	releaseTimeSlider.setValue(80.f);

	// make editor controls visible
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
    g.setFont(12.0f);
    g.drawFittedText("Kaasch compressor", getLocalBounds(), juce::Justification::centredTop, 1);
}

void VstpluginbaseAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
	const int H = getHeight();
	const int W = getWidth();
	const int W_SLIDER = 40;
	const int PAD = 30;

	// bitshift by 1 as quick 2x multiplier
	inputGainSlider.setBounds(PAD, PAD, W_SLIDER, H - (PAD << 1));
	thresholdSlider.setBounds(PAD + 2 * (W_SLIDER + PAD), PAD, W_SLIDER, H - (PAD << 1));
	outputGainSlider.setBounds(W - W_SLIDER - PAD, PAD, W_SLIDER, H - (PAD << 1));
	attackTimeSlider.setBounds(PAD * 2 + W_SLIDER, PAD, W_SLIDER, H - (PAD << 1));
	releaseTimeSlider.setBounds(W - ((W_SLIDER + PAD) << 1), PAD, W_SLIDER, H - (PAD << 1));

}
