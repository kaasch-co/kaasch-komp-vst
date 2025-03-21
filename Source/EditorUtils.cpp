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

UtilResult setupGainSlider(juce::AudioProcessorEditor *editor, juce::Slider *slider) {
	slider->setSliderStyle(juce::Slider::LinearBarVertical);
	slider->setRange(GainRange.FLOOR, GainRange.CEIL, GainRange.STEP);
	slider->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 90, 0);
	slider->setTextValueSuffix(" dB");
	slider->setPopupDisplayEnabled(true, false, editor);
	return OK;
}

UtilResult setupTimeSlider(juce::AudioProcessorEditor *editor, juce::Slider *slider) {
	slider->setSliderStyle(juce::Slider::LinearBarVertical);
	slider->setRange(TimeRange.FLOOR, TimeRange.CEIL, TimeRange.STEP);
	slider->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 90, 0);
	slider->setTextValueSuffix(" ms");
	slider->setPopupDisplayEnabled(true, false, editor);
	return OK;
}


