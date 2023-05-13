#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Piano.h"
class App {
public:
    App();
    void pressKey(int k);
    void relaseKey(int k);
    void run();
private:
    void handleEvents();
    void update();
    void render();
    bool hasFocus = true;
    sf::RenderWindow window;
    Piano piano;
};