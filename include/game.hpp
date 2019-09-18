#ifndef GAME_HPP
#define GAME_HPP


#include <stack>
#include <SFML/Graphics.hpp>
#include "cells.hpp"

class GameState;

class Game
{
    public:

    sf::Event event;
    sf::RenderWindow window;
    sf::Image image;

    int width, length;
    bool run_state=false;

    Cells cells;

    void gameLoop();

    void draw();

    void handleInput();

    Game(int window_width, int window_length);
    ~Game();
};

#endif