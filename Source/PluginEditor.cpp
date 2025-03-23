/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "juce_graphics/juce_graphics.h"
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
    setSize(600, 300);
	
	// Set default values for editor controls
	inputGainSlider.setValue(0.f);
	thresholdSlider.setValue(0.f);
	outputGainSlider.setValue(0.f);

	attackTimeSlider.setValue(20.f);
	releaseTimeSlider.setValue(80.f);

	inputGainSlider.addListener(this);

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
void VstpluginbaseAudioProcessorEditor::paint(juce::Graphics& g) {

	const int W = getWidth();
	const int H = getHeight();
	const int W_SLIDER = 40;
	const int W_TEXT = 40;
	const int PAD = 30;

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);

	// Title
    g.setFont(12.0f);
    g.drawFittedText("KAASCH Kompressor", 0, 0, W, PAD, juce::Justification::centred, 1);

	// Control titles
	g.setFont(10.5f);
	g.drawFittedText("Input", PAD, PAD, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Attack", (PAD << 1) + W_SLIDER, PAD, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Threshold", PAD + ((W_SLIDER + PAD) << 1), PAD, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Release", W - ((W_SLIDER + PAD) << 1), PAD, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Output", W - W_SLIDER - PAD, PAD, W_TEXT, PAD, juce::Justification::centred, 1);


}

void VstpluginbaseAudioProcessorEditor::resized() {
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
	const int W = getWidth();
	const int H = getHeight();
	const int W_SLIDER = 40;
	const int PAD = 30;

	inputGainSlider.setBounds(PAD, PAD << 1, W_SLIDER, H - 3 * PAD);
	thresholdSlider.setBounds(PAD + 2 * (W_SLIDER + PAD), PAD << 1, W_SLIDER, H - 3 * PAD);
	outputGainSlider.setBounds(W - W_SLIDER - PAD, PAD << 1, W_SLIDER, H - 3 * PAD);
	attackTimeSlider.setBounds(PAD * 2 + W_SLIDER, PAD << 1, W_SLIDER, H - 3 * PAD);
	releaseTimeSlider.setBounds(W - ((W_SLIDER + PAD) << 1), PAD << 1, W_SLIDER, H - 3 * PAD);
}

void VstpluginbaseAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
	audioProcessor.inputGainValue = inputGainSlider.getValue();
}
