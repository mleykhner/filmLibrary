//
// Created by Максим Лейхнер on 27.11.2022.
//
#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>

class Button {
public:
    Button(sf::Texture * texture, float height);
    void setPosition(sf::Vector2f point);
    void drawTo(sf::RenderWindow &window);
    sf::Vector2f getSize();
    bool isMouseOver(sf::RenderWindow &window);
private:
    sf::RectangleShape button;
};

