#pragma once

#include <JuceHeader.h>

class DrawWindow : public juce::Component
{
public:
	DrawWindow();
	~DrawWindow();

	void paint(juce::Graphics&) override;
	void mouseDrag(const juce::MouseEvent& event) override;


private:
	static int NUM_SAMPLES;
	std::vector<float> samples;
	std::string out = "hi";
	int debug1;
	int debug2;
	int debug3;

	void drawSamples(juce::Graphics& g);
	int convertXToSamplePosition(int x);
	float convertYToSampleValue(int y);
};

