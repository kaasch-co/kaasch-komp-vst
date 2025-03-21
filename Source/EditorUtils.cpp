#include "PluginEditor.h"
#include "juce_audio_processors/juce_audio_processors.h"

typedef struct _UtilRange {
	const float FLOOR;
	const float CEIL;
	const float STEP;
} UtilRange;

enum UtilResult {
	OK,
	ERR
};



// Decibels
UtilRange GainRange {-40.f, 6.f, 0.1f};

// Milliseconds
UtilRange TimeRange {0.1, 10000.f, 0.1f};

UtilResult addGainSlider(juce::AudioProcessorEditor *editor, juce::Slider *slider, int width) {
	slider->setSliderStyle(juce::Slider::LinearBarVertical);
	slider->setRange(GainRange.FLOOR, GainRange.CEIL, GainRange.STEP);
	slider->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 90, 0);
	return OK;
}

UtilResult addTimeSlider(juce::Slider *slider) {
	slider->setSliderStyle(juce::Slider::LinearBarVertical);
	slider->setRange(TimeRange.FLOOR, TimeRange.CEIL, TimeRange.STEP);
	return OK;
}


