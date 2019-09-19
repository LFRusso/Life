#include <vector>
#include <iostream>
#include "game.hpp"

int main(int argc, char *argv[])
{
    Game game(500, 300);

    game.gameLoop();

    return 0;
}