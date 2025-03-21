#pragma once
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

UtilResult setupGainSlider(juce::AudioProcessorEditor *editor, juce::Slider *slider);
UtilResult setupTimeSlider(juce::AudioProcessorEditor *editor, juce::Slider *slider);

class GainSlider : public juce::Slider {
	public:
		GainSlider(juce::AudioProcessorEditor* editor) {
			this->setSliderStyle(juce::Slider::LinearBarVertical);
			this->setRange(range.FLOOR, range.CEIL, range.STEP);
			this->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 90, 0);
			this->setTextValueSuffix(" dB");
			this->setPopupDisplayEnabled(true, false, editor);
		};

		~GainSlider() {};

	private:
		UtilRange range {-40.f, 6.f, 0.1f};
};
