#include "App.h"
App::App() : window(sf::VideoMode(WIDTH, HEIGHT), "Simple piano")
{
    window.setVerticalSyncEnabled(true);
}
void App::pressKey(int k)
{
    piano.pressKey(k);
}
void App::relaseKey(int k)
{
    piano.release(k);
}
void App::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}
void App::handleEvents()
{
    sf::Event ev;
    while (window.pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::GainedFocus:
            hasFocus = true;
            break;
        case sf::Event::LostFocus:
            hasFocus = false;
            break;
        default:
            break;
        }
    }
}
void App::update()
{

    if (hasFocus)
    {
        piano.update();
    }

}
void App::render()
{
    window.clear(sf::Color::White);
    piano.render(window);
    window.display();
}