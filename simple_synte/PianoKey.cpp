#include "PianoKey.h"

PianoKey::PianoKey(float x, float y, int n) : tone(n) {
    rect.setFillColor(sf::Color::White);
    rect.setSize({ KEY_WIDTH, HEIGHT });
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(KEY_THICKNESS);
    rect.setOutlineColor(sf::Color::Black);
}
void PianoKey::setPressed(bool pressed)
{
    isPressed = pressed;
}
PianoKey::PianoKey(int n) : tone(n)
{
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineThickness(KEY_THICKNESS);
    rect.setOutlineColor(sf::Color::Black);
    isFlatKey = true;
}
bool PianoKey::isFlat()
{
    return isFlatKey;
}
void PianoKey::render(sf::RenderTarget& rt)
{
    rt.draw(rect);
}

void PianoKey::update() {

    if (isPressed)
    {
        if (tone.getStatus() != Tone::Playing)
        {
            tone.play();
            tone.setLoop(true);
            rect.setFillColor(sf::Color::Green);
        }
    }
    else
    {
        tone.setLoop(false);
        if (isFlatKey)
        {
            rect.setFillColor(sf::Color::Black);
        }
        else {
            rect.setFillColor(sf::Color::White);
        }
    }
}
sf::Vector2f PianoKey::getPos()
{
    return rect.getPosition();
}
void PianoKey::putAboveOf(PianoKey& other)
{
    float rightTop = other.getPos().x + KEY_WIDTH;
    rect.setSize({ KEY_WIDTH / 2, HEIGHT / 2 });
    rect.setPosition(rightTop - rect.getSize().x / 2, 0);
}