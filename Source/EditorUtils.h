#pragma once
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
	private:
		const UtilRange range;
		UtilResult setupGainSlider(juce::AudioProcessorEditor*);
		float dbFStoFloat(float);
};

class TimeSlider : public juce::Slider {
	public:
		TimeSlider(juce::AudioProcessorEditor*);
		~TimeSlider();
	private:
		const UtilRange range;
		UtilResult setupTimeSlider(juce::AudioProcessorEditor*);
};


