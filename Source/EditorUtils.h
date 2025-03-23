#pragma once
#include "juce_gui_basics/juce_gui_basics.h"
#include <JuceHeader.h>

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
		float dbFStoFloat();
	private:
		const UtilRange range;
		UtilResult setupGainSlider(juce::AudioProcessorEditor*);
};

class TimeSlider : public juce::Slider {
	public:
		TimeSlider(juce::AudioProcessorEditor*);
		~TimeSlider();
	private:
		const UtilRange range;
		UtilResult setupTimeSlider(juce::AudioProcessorEditor*);
};

class DecibelMeter : juce::Drawable {
	public:
		DecibelMeter();
		~DecibelMeter();

	private:
		const UtilRange range;
		float value;
};
