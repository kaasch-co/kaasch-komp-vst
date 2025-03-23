/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "EditorUtils.h"
#include "juce_graphics/juce_graphics.h"
#include "juce_gui_basics/juce_gui_basics.h"

//==============================================================================
/**
*/
class VstpluginbaseAudioProcessorEditor : public juce::AudioProcessorEditor, 
										private juce::Slider::Listener {
public:
    VstpluginbaseAudioProcessorEditor (VstpluginbaseAudioProcessor&);
    ~VstpluginbaseAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
	void sliderValueChanged(juce::Slider* slider) override;

	juce::Image backgroundImage;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstpluginbaseAudioProcessor& audioProcessor;

	GainSlider inputGainSlider{this};
	GainSlider thresholdSlider{this};
	GainSlider outputGainSlider{this};
	TimeSlider attackTimeSlider{this};
	TimeSlider releaseTimeSlider{this};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstpluginbaseAudioProcessorEditor)
};
