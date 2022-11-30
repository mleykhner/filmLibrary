#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include "TextBox.h"
#include "TextButton.h"

using namespace std;

#define UI_SCALE 1.0f

int main() {
    //Настройки окна программы
    string title = "Фильмотека";
    const int windowHeight = 1024 * UI_SCALE;
    const int windowWidth = 1440 * UI_SCALE;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    //Вызов окна
    sf::RenderWindow window(
            sf::VideoMode(
                    windowWidth,
                    windowHeight),
                    sf::String::fromUtf8(
                            title.begin(),
                            title.end()),
                            sf::Style::Close,
                            settings);
    window.setFramerateLimit(60);

    //Генерируем текстуру фона
    sf::Texture backgroundTexture = createBackgroundTexture(
            windowWidth,
            windowHeight,
            sf::Color(65, 65, 65));
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(windowWidth, windowHeight));
    background.setTexture(&backgroundTexture);

    //Подключаем файлы шрифтов
    sf::Font helveticaNeue_Light;
    sf::Font helveticaNeue_Regular;
    sf::Font helveticaNeue_Medium;
    sf::Font helveticaNeue_Bold;
    if(!(helveticaNeue_Light.loadFromFile("/Users/mleykhner/Desktop/filmLibrary/resources/HelveticaNeueCyr-Light.ttf") &&
            helveticaNeue_Regular.loadFromFile("/Users/mleykhner/Desktop/filmLibrary/resources/HelveticaNeueCyr-Roman.ttf") &&
            helveticaNeue_Medium.loadFromFile("/Users/mleykhner/Desktop/filmLibrary/resources/HelveticaNeueCyr-Medium.ttf") &&
            helveticaNeue_Bold.loadFromFile("/Users/mleykhner/Desktop/filmLibrary/resources/HelveticaNeueCyr-Bold.ttf"))){
        throw "FILE_NOT_LOAD";
    }

    //Подключаем файлы текстур
    sf::Texture searchTexture;
    if(!(searchTexture.loadFromFile("/Users/mleykhner/Desktop/filmLibrary/resources/textBox_texture.png"))){
        throw "FILE_NOT_LOAD";
    }

    //Загружаем курсоры мыши из системы
    sf::Cursor arrowCursor;
    sf::Cursor handCursor;
    sf::Cursor textCursor;
    arrowCursor.loadFromSystem(sf::Cursor::Arrow);
    handCursor.loadFromSystem(sf::Cursor::Hand);
    textCursor.loadFromSystem(sf::Cursor::Text);

    //Инициализируем элементы интерфейса
    TextBox searchBox(&searchTexture, 49 * UI_SCALE);
    searchBox.setPosition(sf::Vector2f(992 * UI_SCALE, 38 * UI_SCALE));
    searchBox.setFont(helveticaNeue_Medium);
    searchBox.setArrowCursor(&arrowCursor);
    searchBox.setTextCursor(&textCursor);

    TextButton searchType(&helveticaNeue_Bold, 49 * UI_SCALE);
    searchType.setPosition(sf::Vector2f(86 * UI_SCALE, 38 * UI_SCALE));
    searchType.setText(L"Фильмы");
    searchType.setArrowCursor(&arrowCursor);
    searchType.setHandCursor(&handCursor);

    //Обновление кадра
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(searchBox.isMouseOver(window)){
                        searchBox.setSelected(true);
                    }
                    else{
                        searchBox.setSelected(false);
                    }
                    break;
                case sf::Event::TextEntered:
                    searchBox.typedOn(event);
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(background);
        searchBox.drawTo(window);
        //window.draw(films);
        searchType.onHover(window, searchType.isMouseOver(window));
        searchBox.onHover(window, searchBox.isMouseOver(window));
        searchType.drawTo(window);
        window.display();
    }

    return 0;
}