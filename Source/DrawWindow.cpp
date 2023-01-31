#include "DrawWindow.h"
#include "PluginProcessor.h"


using namespace juce;
using std::string;
using std::to_string;

int DrawWindow::NUM_SAMPLES = 100;


DrawWindow::DrawWindow(WaveDrawerAudioProcessor& p) 
    : audioProcessor(p)
{
    samples = std::vector<float>();
    for (int i = 0; i < NUM_SAMPLES; i++) {
        samples.push_back(0);
    }
}

DrawWindow::~DrawWindow()
{
}




void DrawWindow::paint(Graphics& g) {

    Rectangle<float> box = getLocalBounds().toFloat();


    g.setColour(juce::Colours::darkgrey);
    g.fillRoundedRectangle(box, 3);

    g.setColour(juce::Colours::grey);
    g.drawRoundedRectangle(box, 3, 3);

    drawSamples(g);

    g.setFont(15.0f);
    g.drawFittedText(out, getLocalBounds(), Justification::centred, 1);

}



void DrawWindow::mouseDrag(const MouseEvent& event)
{
    Point<int> point = event.getPosition();
    out = std::to_string(point.x) + " " + std::to_string(point.y);

    Rectangle<float> box = getLocalBounds().toFloat();

    if (point.y > 0 && point.y < box.getHeight()) {
        int sam = convertXToSamplePosition(point.x);
        if (sam > 0 && sam < samples.size()) {
            samples[sam] = convertYToSampleValue(point.y);
            debug1 = samples[sam];
        }
    }

    audioProcessor.setSamples(samples);
    repaint();
}

void DrawWindow::drawSamples(Graphics& g)
{
    float width = getLocalBounds().toFloat().getWidth() - 2;
    float height = getLocalBounds().toFloat().getHeight() - 2;

    float xStep = width / samples.size();
    float xPos = 1;
    float yStep = height / 2;

    for (int i = 1; i < samples.size() - 1; i++)
    {
        Line<float> line = Line<float>(xPos, samples[i] * yStep + height / 2, xPos + xStep, samples[i+1] * yStep + height / 2);
        g.drawLine(line);
        xPos += xStep;
    }
}

int DrawWindow::convertXToSamplePosition(int x) {
    float width = getLocalBounds().toFloat().getWidth() - 2;
    float xStep = width / samples.size();
    return (int) floor(x / xStep);
}

float DrawWindow::convertYToSampleValue(int y) {
    float height = getLocalBounds().toFloat().getHeight() - 2;
    float yStep = height / 2;
    return (y - height / 2) / yStep;
}



