#include <vector>
#include <iostream>
#include "game.hpp"

int main(int argc, char *argv[])
{
    Game game(1000, 600);

    game.gameLoop();

    return 0;
}