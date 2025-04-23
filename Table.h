#pragma once
#include <vector>
#include <numeric> // For std::iota

class Table {
public:
    Table(int width, int height);

    void addSable(int x, int y);
    void addObstacle(int x, int y);
    void update(); // Update the table for the simulation
    void display() const;
    void clear(); // Clears the table

    const std::vector<std::vector<int>>& getGrid() const;

private:
    int width;
    int height;
    std::vector<std::vector<int>> grid; // 0 = empty, 1 = sand, 2 = obstacle
};
