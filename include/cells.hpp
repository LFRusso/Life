#ifndef CELLS_HPP
#define CELLS_HPP

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

class Cells
{

public:

    int cols{0}, rows{0};
    std::vector<std::vector<int>> state;
    std::vector<std::vector<int>> old_state;
    int cell_count=0;

    void addCell(sf::Vector2i position);

    void peakState();

    int cellCount() const;

    void updateState();

    int cellPositions() const;

    void setMatrix(int m, int n);

    int countNeighborhood(int x, int y);

    std::vector<std::vector<int>> copy_state(std::vector<std::vector<int>> const vec);

    void kill();
};

#endif