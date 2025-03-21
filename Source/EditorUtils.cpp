#include "juce_audio_processors/juce_audio_processors.h"
#include "EditorUtils.h"

// Decibels
const UtilRange GainRange {-40.f, 6.f, 0.1f};

// Milliseconds
const UtilRange TimeRange {0.1, 10000.f, 0.1f};

GainSlider::GainSlider(juce::AudioProcessorEditor* editor) : range(GainRange) {
	setupGainSlider(editor);
};

GainSlider::~GainSlider() {};

UtilResult GainSlider::setupGainSlider(juce::AudioProcessorEditor *editor) {
	this->setSliderStyle(juce::Slider::LinearBarVertical);
	this->setRange(range.FLOOR, range.CEIL, range.STEP);
	this->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 90, 0);
	this->setTextValueSuffix(" dB");
	this->setPopupDisplayEnabled(true, false, editor);
	return OK;
}

UtilResult GainSlider::setupTimeSlider(juce::AudioProcessorEditor *editor) {
	this->setSliderStyle(juce::Slider::LinearBarVertical);
	this->setRange(range.FLOOR, range.CEIL, range.STEP);
	this->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 90, 0);
	this->setTextValueSuffix(" ms");
	this->setPopupDisplayEnabled(true, false, editor);
	return OK;
}


