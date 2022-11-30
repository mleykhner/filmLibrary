#include <SFML/Graphics.hpp>


struct moviesList;
class Movie;

class Director{
public:
    Director(std::string firstname, std::string lastname);
    void setPortraitTexture(sf::Texture * portrait);
    void setPortraitSize(float diameter);
    void setPortraitPosition(sf::Vector2f point);
    void setPortraitFont(sf::Font * font);
    sf::Drawable * getPortrait();
    void setMoviesList(moviesList * moviesList);
    void addMovie(Movie * movie);
    Movie * getMovie(std::string title);
private:
    std::string firstname;
    std::string lastname;
    std::string biography;
    moviesList * movies; //TODO: Добавить в конструктор создание нового списка фильмов
    Director * nextDirector;
    Director * previousDirector;
    sf::CircleShape portrait;
    sf::Text text;
};

class Movie {
private:
    std::string title;
    std::string synopsis;
    Director * director = nullptr;
    std::string originCountry;
    sf::Texture * poster = nullptr;
    int yearOfRelease;
    int budget;
    int boxOffice;
    float imdbRating;
    Movie * nextMovie = nullptr;
    Movie * previousMovie = nullptr;
    bool seen = false;
};

struct directorsDatabase {
    Director * firstDirector;
    Director * lastDirector;
    int size = 0;
};

struct moviesList {
    Movie * firstMovie;
    Movie * lastMovie;
    int size = 0;
};