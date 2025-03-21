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

class GainSlider : public juce::Slider {
	public:
		GainSlider(juce::AudioProcessorEditor*);
		~GainSlider();
	private:
		const UtilRange range;
		UtilResult setupGainSlider(juce::AudioProcessorEditor*);
		UtilResult setupTimeSlider(juce::AudioProcessorEditor*);
};
