#pragma once
#include <vector>
#include <numeric> // For std::iota

class Table {
public:
    Table(int width, int height);

    void addSable(int x, int y);
    void addObstacle(int x, int y);
    void addBubble(int x, int y);
    void updateSand();
    void updateBubble();
    void display() const;
    void clearCell(int x, int y); // Clears a specific cell
    void clear(); // Clears the table

    const std::vector<std::vector<int>>& getGrid() const;

private:
    int width;
    int height;
    std::vector<std::vector<int>> grid; // 0 = empty, 1 = sand, 2 = obstacle
};
