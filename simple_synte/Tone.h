#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "Config.h"
#include <iostream>
static const float START_FREQ = 8.1758f;
static const float RATIO = 1.0594630943592953f;

static float getFreq(int i)
{
    return START_FREQ * std::pow(RATIO, i);
}

static float map(float n, float x1, float x2, float y1, float y2)
{
    float m = (y2 - y1) / (x2 - x1);
    return y1 + m * (n - x1);
}
static sf::Int16 squarewave(float t, float freq)
{
    int output = std::floor(2 * freq * t);
    return 32767 * (output & 1 ? -1 : 1);
}
static sf::Int16 sawtooth(float t, float freq)
{
    float T = 1.0f / freq;
    float start = T * std::floor(t / T);
    float end = start + T;
    return 32767 * map(t, start, end, -1.0f, 1.0f);
}
class Tone : public sf::Sound
{
public:
    Tone() {}
    Tone(int n)
    {
        std::vector<sf::Int16> samples;
        float t = 0;
        float dt = 1.0f / SAMPLE_RATE;
        float freq = getFreq(n);
        std::cout << freq << "\n";
        int nsamples = SAMPLE_RATE * (1.0f / freq);

        for (int i = 0; i < nsamples; i++)
        {
            sf::Int16 sample = squarewave(t, freq);
            t += dt;
            samples.push_back(sample); //left channel
            samples.push_back(sample); //right
        }
        buffer.loadFromSamples(samples.data(), samples.size(), 2, SAMPLE_RATE);
        setBuffer(buffer);
    }
private:
    sf::SoundBuffer buffer;
};