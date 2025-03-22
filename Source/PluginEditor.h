/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "EditorUtils.h"

//==============================================================================
/**
*/
class VstpluginbaseAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VstpluginbaseAudioProcessorEditor (VstpluginbaseAudioProcessor&);
    ~VstpluginbaseAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstpluginbaseAudioProcessor& audioProcessor;
	/* controls for compressor
	juce::Slider inputGainSlider;
	juce::Slider attackTimeSlider;
	juce::Slider releaseTimeSlider;
	juce::Slider thresholdSlider;
	juce::Slider outputGainSlider;
	*/

	GainSlider inputGainSlider{this};
	GainSlider thresholdSlider{this};
	GainSlider outputGainSlider{this};

	TimeSlider attackTimeSlider{this};
	TimeSlider releaseTimeSlider{this};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstpluginbaseAudioProcessorEditor)
};
