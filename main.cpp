#include <iostream>
#include <string>
//#include <SFML/Graphics.hpp> //Добаивть библиотеку в CMakeList.txt
#include "math.h"
using namespace std;

struct movie;
struct director;
struct moviesList;

struct director {
    string firstname;
    string lastname;
    string biography;
    string portraitLink;
    moviesList * films;
    director * nextDirector;
    director * previousDirector;
};

struct movie {
    string title;
    string synopsis;
    director * director;
    string originCountry;
    string posterLink;
    int yearOfRelease;
    int budget;
    int boxOffice;
    movie * nextMovie;
    movie * previousMovie;
    bool seen;
};

struct directorsDatabase {
    director * firstDirector;
    director * lastDirector;
    int size = 0;
};

struct moviesList {
    movie * firstMovie;
    movie * lastMovie;
    int size = 0;
};

void addDirector(directorsDatabase * dDatabase, director * newDirector){
    if(!dDatabase->size){ //Если список режиссёров пустой
        //Новый режиссёр будет и первым и последним
        dDatabase->firstDirector = newDirector;
        dDatabase->lastDirector = newDirector;
        dDatabase->size++;
    }
    else //Если список не пустой
    {    // Добавляем нового режиссёра в конец списка
        dDatabase->lastDirector->nextDirector = newDirector;
        newDirector->previousDirector = dDatabase->lastDirector;
        dDatabase->lastDirector = newDirector;
        dDatabase->size++;
    }
}



void addMovie(moviesList * mList, movie * newMovie){
    if(!mList->size){ //Если список фильмов пустой
        //Новый фильм будет и первым и последним
        mList->firstMovie = newMovie;
        mList->lastMovie = newMovie;
        mList->size++;
    }
    else //Если список не пустой
    {    // Добавляем новый фильм в конец списка
        mList->lastMovie->nextMovie = newMovie;
        newMovie->previousMovie = mList->lastMovie;
        mList->lastMovie = newMovie;
        mList->size++;
    }
}

movie getMovie(director director, int index){
    if(index >= director.films->size){
        throw "noSuchMovie_error"; // Код ошибки: выход за пределы списка фильмов
    }
    movie * desiredMovie = director.films->firstMovie;
    for(int i = 0; i < index; i++){
        desiredMovie = desiredMovie->nextMovie;
    }
    return *desiredMovie;
}


int main() {
    /*string title = "Фильмотека";
    sf::RenderWindow window(sf::VideoMode(1440, 960), sf::String::fromUtf8(title.begin(), title.end()));
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //Тут рисуй
        window.display();
    }*/

    directorsDatabase * myDatabase = new directorsDatabase;
    director * newDirector = new director;
    addDirector(myDatabase, newDirector);
    newDirector->firstname = "Bebra";
    newDirector->lastname = "Bebrovich";
    newDirector->films = new moviesList;
    movie * newMovie1 = new movie;
    movie * newMovie2 = new movie;
    movie * newMovie3 = new movie;
    addMovie(newDirector->films, newMovie1);
    addMovie(newDirector->films, newMovie2);
    addMovie(newDirector->films, newMovie3);
    newMovie1->title = "Я – Бебра";
    newMovie2->title = "Бебринский клуб";
    //newMovie3->title = "В поисках Бебры";

    try{
        string movieTitle = getMovie(*myDatabase->firstDirector, 3).title;
        std::cout << "director: "
                  << myDatabase->firstDirector->firstname + " " + myDatabase->firstDirector->lastname
                  << ", movie: " << movieTitle << std::endl;
    }
    catch(char const * x){
        if (x == "noSuchMovie_error"){
            std::cout << "У этого режиссера нет такого фильма :((" << std::endl;
        }
    }

    return 0;
}