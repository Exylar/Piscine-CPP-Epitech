/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DisplaySFML
*/

#include "../include/DisplaySFML.hpp"
#include <chrono>
#include <thread>

DisplaySFML::DisplaySFML() : _pos(10), _window(sf::VideoMode(720, 1280), "myGKrellm"), _shift(0)
{
    pixels = new sf::Uint8[720 * 1280 * 4];
    _texture.create(720, 720);
    for (int i = 0; i < 720; i++) {
        for (int j = 0; j < 720; j++) {
            putpixel(j, i);
        }
    }
}

DisplaySFML::~DisplaySFML()
{
    delete[] (pixels);
}

void DisplaySFML::Update()
{
    _pos = 10;
    _window.display();
}

bool DisplaySFML::isOpen()
{
    sf::Event event;
    _window.clear(sf::Color::Black);
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        return (_window.isOpen());
}

void DisplaySFML::fillTexture()
{
    for (int i = 0; i < 719; i++) {
        for (int j = 0; j < 720; j++) {
            pixels[(i % 720 + j % 1280 * 720) * 4 + 0] = pixels[((i + 1) % 720 + j % 1280 * 720) * 4 + 0];
            pixels[(i % 720 + j % 1280 * 720) * 4 + 1] = pixels[((i + 1) % 720 + j % 1280 * 720) * 4 + 1];
            pixels[(i % 720 + j % 1280 * 720) * 4 + 2] = pixels[((i + 1) % 720 + j % 1280 * 720) * 4 + 2];
            pixels[(i % 720 + j % 1280 * 720) * 4 + 3] = pixels[((i + 1) % 720 + j % 1280 * 720) * 4 + 3];
            pixels[(i % 720 + j % 1280 * 720) * 4 + 3] /= 1.001;
        }
    }
    _texture.update(pixels);
    sf::Sprite sprite(_texture);
    _window.draw(sprite);
}

void DisplaySFML::putpixel(int x, int y, sf::Color color)
{
    if (y >= 1280)
        return;
    int xpos = x % 720 - _shift;
    xpos = (xpos < 0) ? 0 : xpos;
    int pos = ((xpos) + y % 1280 * 720) * 4;

    pixels[pos + 0] = color.r;
    pixels[pos + 1] = color.g;
    pixels[pos + 2] = color.b;
    pixels[pos + 3] = color.a;
}

void DisplaySFML::putpixel(int x, int y)
{
    if (y >= 1280)
        return;
    int xpos = x % 720 - _shift;
    xpos = (xpos < 0) ? 0 : xpos;
    int pos = ((xpos) + y % 720 * 1280) * 4;

    pixels[pos + 0] = 0;
    pixels[pos + 1] = 0;
    pixels[pos + 2] = 0;
    pixels[pos + 3] = 0;
}

void DisplaySFML::DisplayTitle(std::string str)
{
    sf::Font font;
    font.loadFromFile("m5x7.ttf");
    sf::Text text(str, font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition((sf::Vector2f){10, (float)(_pos)});
    _window.draw(text);
    _pos += 55;
}

void DisplaySFML::DisplaySubTitle(std::string str)
{
    sf::Font font;
    font.loadFromFile("m5x7.ttf");
    sf::Text text(str, font, 35);
    text.setFillColor(sf::Color::White);
    text.setPosition((sf::Vector2f){25, (float)(_pos)});
    _window.draw(text);
    _pos += 45;
}

void DisplaySFML::DisplayText(std::string str)
{
    sf::Font font;
    font.loadFromFile("m5x7.ttf");
    sf::Text text(str, font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition((sf::Vector2f){45, (float)(_pos)});
    _window.draw(text);
    _pos += 40;
}

void DisplaySFML::DisplaySeparator()
{
    sf::RectangleShape shape((sf::Vector2f){720, 5});
    shape.setPosition((sf::Vector2f){0, (float)(_pos)});
    _pos += 10;
    shape.setFillColor(sf::Color::White);
    _window.draw(shape);
}

void DisplaySFML::DisplayBar(std::string name, int value)
{
    if (value >= 100)
        value = 100;
    DisplaySubTitle(name);
    sf::RectangleShape shape((sf::Vector2f){400, 20});
    shape.setPosition((sf::Vector2f){15, (float)(_pos)});
    shape.setFillColor((sf::Color){100, 100, 100, 255});
    _window.draw(shape);
    sf::RectangleShape shape2((sf::Vector2f){(float)((400 * value / 100)), 16});
    shape2.setPosition((sf::Vector2f){17, (float)(_pos + 2)});
    shape2.setFillColor(sf::Color::White);
    sf::Font font;
    font.loadFromFile("m5x7.ttf");
    sf::Text text(std::to_string(value) + "%", font, 16);
    text.setFillColor(sf::Color::White);
    text.setPosition((sf::Vector2f){425, (float)(_pos - 2)});
    _window.draw(text);
    _pos += 25;
    _window.draw(shape2);
}

void DisplaySFML::DisplayGraph(std::string name, int value)
{
    if (value >= 100)
        value = 100;
    DisplaySubTitle(name);
    sf::RectangleShape shape((sf::Vector2f){502, 104});
    shape.setPosition((sf::Vector2f){00, (float)(_pos - 2)});
    shape.setFillColor((sf::Color){100, 100, 100, 255});
    _window.draw(shape);
    putpixel(500, _pos + 100 - value, sf::Color::White);
    fillTexture();
    _pos += 110;
}

bool *DisplaySFML::GetModules()
{
    static bool activate[7] = {true, true, true, false, false, false, false};
    static bool clicks[7] = {false, false, false, false, false, false, false};

    activate[0] = (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !clicks[0]) ? !activate[0] : activate[0];
    activate[1] = (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !clicks[1]) ? !activate[1] : activate[1];
    activate[2] = (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !clicks[2]) ? !activate[2] : activate[2];
    activate[3] = (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !clicks[3]) ? !activate[3] : activate[3];
    activate[4] = (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && !clicks[4]) ? !activate[4] : activate[4];
    activate[5] = (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !clicks[5]) ? !activate[5] : activate[5];

    clicks[0] = (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ? true : false;
    clicks[1] = (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) ? true : false;
    clicks[2] = (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) ? true : false;
    clicks[3] = (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) ? true : false;
    clicks[4] = (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) ? true : false;
    clicks[5] = (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) ? true : false;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    activate[6] = (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) ? true : false;
    return (activate);
}