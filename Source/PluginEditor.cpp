/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "BinaryData.h"
#include "PluginProcessor.h"
#include "juce_audio_processors/juce_audio_processors.h"
#include "juce_core/juce_core.h"
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

	// setup background image
	backgroundImage = juce::ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);

	// make editor controls visible
	addAndMakeVisible(inputGainSlider);
	addAndMakeVisible(thresholdSlider);
	addAndMakeVisible(outputGainSlider);
	addAndMakeVisible(attackTimeSlider);
	addAndMakeVisible(releaseTimeSlider); 
	
	// add listeners to the controls
	inputGainSlider.addListener(this);
	thresholdSlider.addListener(this);
	outputGainSlider.addListener(this);
	attackTimeSlider.addListener(this);
	releaseTimeSlider.addListener(this);	

	// Set proper colors for controls
	getLookAndFeel().setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::white);
	getLookAndFeel().setColour(juce::Slider::ColourIds::textBoxBackgroundColourId, juce::Colour(137, 200, 204));
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
	g.drawImage(backgroundImage, 0, 0, W, H, 0, 0, backgroundImage.getWidth(), backgroundImage.getHeight());

	// Control titles
	g.setFont(10.5f);
	g.setColour(juce::Colours::white);
	g.drawFittedText("Input", PAD, PAD << 1, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Attack", (PAD << 1) + W_SLIDER, PAD << 1, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Threshold", PAD + ((W_SLIDER + PAD) << 1), PAD << 1, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Release", W - ((W_SLIDER + PAD) << 1), PAD << 1, W_TEXT, PAD, juce::Justification::centred, 1);
	g.drawFittedText("Output", W - W_SLIDER - PAD, PAD << 1, W_TEXT, PAD, juce::Justification::centred, 1);

	// Gain meter
	g.drawRect(PAD + ((W_SLIDER + PAD) << 2), PAD << 1, W_SLIDER, H - (PAD << 2));
	g.drawRect(PAD + ((W_SLIDER + PAD) << 2) + 4, (PAD << 1) + 4, W_SLIDER - 8, H - 8 - (PAD << 2));

}

void VstpluginbaseAudioProcessorEditor::resized() {
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
	const int W = getWidth();
	const int H = getHeight();
	const int W_SLIDER = 40;
	const int PAD = 30;

	inputGainSlider.setBounds(PAD, PAD * 3, W_SLIDER, H - (PAD << 2));
	thresholdSlider.setBounds(PAD + 2 * (W_SLIDER + PAD), PAD * 3, W_SLIDER, H - (PAD << 2));
	outputGainSlider.setBounds(W - W_SLIDER - PAD, PAD * 3, W_SLIDER, H - (PAD << 2));
	attackTimeSlider.setBounds(PAD * 2 + W_SLIDER, PAD * 3, W_SLIDER, H - (PAD << 2));
	releaseTimeSlider.setBounds(W - ((W_SLIDER + PAD) << 1), PAD * 3, W_SLIDER, H - (PAD << 2));
}

void VstpluginbaseAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
	// Convert between physical and digital units happen here, so the audioprocessor only
	// implements the correct unit

	// If statements to only update the values of sliders that have changed
	if (slider == &inputGainSlider) {
		audioProcessor.inputGainValue = inputGainSlider.dbFStoFloat();
	}
	
	if (slider == &thresholdSlider) {
		audioProcessor.thresholdValue = thresholdSlider.dbFStoFloat();
	}

	if (slider == &outputGainSlider) {
		audioProcessor.outputGainValue = outputGainSlider.dbFStoFloat();
	}

}
