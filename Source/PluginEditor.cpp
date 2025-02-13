/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "juce_gui_basics/juce_gui_basics.h"
#include "PluginEditor.h"

//==============================================================================
VstpluginbaseAudioProcessorEditor::VstpluginbaseAudioProcessorEditor (VstpluginbaseAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	volumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	volumeSlider.setRange(0u, 127u, 1u);
	volumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
	volumeSlider.setPopupDisplayEnabled(true, false, this);
	volumeSlider.setTextValueSuffix("Volume");
	volumeSlider.setValue(0u);

	addAndMakeVisible(&volumeSlider);
}

VstpluginbaseAudioProcessorEditor::~VstpluginbaseAudioProcessorEditor()
{
}

//==============================================================================
void VstpluginbaseAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);
    g.setFont(juce::FontOptions (15.0f));
    g.drawFittedText("Input test", getLocalBounds(), juce::Justification::topLeft, 1);
}

void VstpluginbaseAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
	volumeSlider.setBounds(40, 30, 20, getHeight() - 60);
}
