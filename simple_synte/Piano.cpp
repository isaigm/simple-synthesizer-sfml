#include "Piano.h"
#include <iostream>
Piano::~Piano()
{
    for (int i = 0; i < keys.size(); i++)
    {
        delete keys[i];
    }
}
Piano::Piano() {
    for (int i = 0; i < OCTAVES; i++)
    {
        addOctave();
    }
}
void Piano::pressKey(int k)
{
    keys[k]->setPressed(true);
}
void Piano::release(int k)
{
    keys[k]->setPressed(false);
}
void Piano::update()
{
    for (auto& key : keys)
    {
        key->update();
    }
}
void Piano::render(sf::RenderTarget& rt)
{
    for (auto& key : keys)
    {
        if (!(key->isFlat())) key->render(rt);
    }
    for (auto& key : keys)
    {
        if (key->isFlat())key->render(rt);
    }
}
void Piano::addOctave()
{
    bool flatOrWhite[] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };
    for (int i = 0; i < 12; i++)
    {
        if (flatOrWhite[i])
        {
            PianoKey* key = new PianoKey(currKey);
            key->putAboveOf(*keys.back());
            keys.push_back(key);
        }
        else
        {
            PianoKey* key = new PianoKey(currX, 0, currKey);
            currX += (KEY_WIDTH + KEY_THICKNESS);
            keys.push_back(key);
        }
        currKey++;
    }
}