#include <SFML/Graphics.hpp>
#include "Elements.h"
#include "TextBox.h"

Button::Button(sf::Texture * texture, float height) {
    float scale = height / texture->getSize().y;
    button.setSize(sf::Vector2f(texture->getSize().x * scale, texture->getSize().y * scale));
    button.setTexture(texture);
}
void Button::setPosition(sf::Vector2f point) {
    button.setPosition(point);
}
void Button::drawTo(sf::RenderWindow &window) {
    window.draw(button);
}
sf::Vector2f Button::getSize() {
    return button.getSize();
}
bool Button::isMouseOver(sf::RenderWindow &window) {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    int btnPosX = button.getPosition().x;
    int btnPosY = button.getPosition().y;

    int btnxPosWidth = button.getPosition().x + button.getSize().x;
    int btnyPosHeight = button.getPosition().y + button.getSize().y;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
        return true;
    }
    return false;
}

