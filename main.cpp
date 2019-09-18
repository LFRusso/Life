#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include "cells.hpp"
#include "game.hpp"

int main(int argc, char *argv[])
{
    Game game(1000, 600);

    game.gameLoop();

    return 0;
}