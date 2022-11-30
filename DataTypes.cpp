//
// Created by Максим Лейхнер on 29.11.2022.
//

#include "DataTypes.h"

Director::Director(std::string firstname, std::string lastname) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->movies = new moviesList;
    this->portrait.setRadius(64);
    sf::RenderTexture avatar;
    avatar.create(100, 100);
    avatar.clear();
}
