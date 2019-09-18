#include "cells.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

void Cells::addCell(sf::Vector2i position)
{
    state[position.x*0.1][position.y*0.1] = 1;
    this->cell_count += 1;
}

int Cells::cellCount() const
{
    return this->cell_count;
}

void Cells::updateState()
{
    old_state = this->copy_state(state);
    for (int i=1; i<rows-1; i++)
    {
        for (int j=1; j<cols-1; j++)
        {
            switch (this->countNeighborhood(i, j))
            {
            case 2:
                if (old_state[i][j] == 1)
                    state[i][j] = 1; 
                else 
                    state[i][j] = 0;
                break;
            
            case 3:
                state[i][j] = 1;
                break;

            default:
                state[i][j] = 0;
                break;
            }
        }
    }
    
}

int Cells::countNeighborhood(int x, int y)
{
    int count{0};

    for (int i=x-1; i<=x+1; i++)
    {   
        for (int j=y-1; j<=y+1; j++)
        {
            if(i!=x or j!=y){
                if(old_state[i][j] == 1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

std::vector<std::vector<int>> Cells::copy_state(std::vector<std::vector<int>> const vec)
{
    std::vector<std::vector<int>> v(vec);
    return v;
}

void Cells::setMatrix(int m, int n)
{
    rows = m+2;
    cols = n+2;
    state.resize(rows, std::vector<int>(cols, 0));
}

void Cells::kill()
{
    state.clear();
    old_state.clear();
}