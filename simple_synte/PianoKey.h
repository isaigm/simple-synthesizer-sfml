#pragma once
#include <SFML/Graphics.hpp>
#include "Tone.h"
#include "Config.h"
static const float KEY_WIDTH = float(WIDTH) / (7 * OCTAVES);
static const float KEY_THICKNESS = 1.0f;
class PianoKey
{
public:
    PianoKey(float x, float y, int n);
    void setPressed(bool pressed);
    PianoKey(int n);
    bool isFlat();
    void render(sf::RenderTarget& rt);
    void update();
    sf::Vector2f getPos();
    void putAboveOf(PianoKey& other);
private:
    sf::RectangleShape rect;
    bool isFlatKey = false;
    bool isPressed = false;
    Tone tone;
};