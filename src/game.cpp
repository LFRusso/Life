#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "cells.hpp"

void Game::handleInput()
{
    while(window.pollEvent(event))
    switch (event.type)
    {
    case sf::Event::Closed:
        this->~Game();
        break;
    
    case sf::Event::KeyPressed:
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            run_state = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            run_state = false;
        break;

    case sf::Event::MouseButtonPressed:
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            cells.addCell(sf::Vector2i(sf::Mouse::getPosition(window)));
        }
        break;
    
    default:
        break;
    }

}


void Game::draw()
{
    sf::RectangleShape cell;
    cell.setFillColor(sf::Color::Black);
    cell.setSize(sf::Vector2f(width/(width*0.1), length/(length*0.1)));

    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f(width/(width*0.1), length/(length*0.1)));

    int count=0;

    for (int i=0; i<width*0.1; i++)
    {
        count++;
        for (int j=0; j<length*0.1; j++)
        {
            if(count%2==1)
            {
                tile.setFillColor(sf::Color(0, 0, 0, 50));
            } else {
                tile.setFillColor(sf::Color::White);
            }
            tile.setPosition(sf::Vector2f(i*10, j*10));
            window.draw(tile);
            count++;

            if(cells.state[i][j] == 1)
            {
                cell.setPosition(sf::Vector2f(i*10, j*10));
                window.draw(cell);
            }
        }
    }
}


void Game::gameLoop(){

    while(this->window.isOpen())
    {

        this->handleInput();
        this->window.clear(sf::Color::White);
        this->draw();
        if(run_state)
            cells.updateState();
        this->window.display();
    }
}


Game::Game(int window_width, int window_length)
{
    int m = window_width*0.1;
    int n = window_length*0.1;


    width = window_width;
    length = window_length;
    this->window.create(sf::VideoMode(width, length), "Game of Life");
    this->window.setFramerateLimit(10);

    image.create(width, length, sf::Color::White);

    cells.setMatrix(m, n);
}

Game::~Game()
{
    cells.kill();
    window.close();
    std::exit(0);
}