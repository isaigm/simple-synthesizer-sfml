#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "PianoKey.h"
class Piano
{
public:
    ~Piano();
    Piano();
    void pressKey(int k);
    void release(int k);
    void update();
    void render(sf::RenderTarget& rt);
private:
    void addOctave();
    float currX = 0;
    int currKey = 0;
    std::vector<PianoKey*> keys;
};