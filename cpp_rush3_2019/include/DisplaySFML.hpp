/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DisplaySFML
*/

#ifndef DISPLAYSFML_HPP_
#define DISPLAYSFML_HPP_

#include "IMonitorDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>


class DisplaySFML : public IMonitorDisplay {
	public:
		DisplaySFML();
		~DisplaySFML();

        bool isOpen();
        void Update();
        void DisplayTitle(std::string str);
        void DisplaySubTitle(std::string str);
        void DisplayText(std::string str);
        void DisplayBar(std::string name, int value);
        void DisplayGraph(std::string name, int value);
        void DisplaySeparator();
        bool *GetModules();

    private:
        void fillTexture();
        void putpixel(int x, int y, sf::Color c);
        void putpixel(int x, int y);
        void clearbuffer();

	private:
        int _pos;
        sf::Texture _texture;
        sf::RenderWindow _window;
        sf::Uint8 *pixels;
        int _shift;
};

#endif /* !DISPLAYSFML_HPP_ */
