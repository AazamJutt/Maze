//
// Created by XXX on YYY.
//

#pragma once

#include "maze.h"
#include <ostream>

class Creature {
  public:
    friend ostream& operator<<(ostream& out, const Creature& creature);

  public:
    Creature(int row, int col);
    string solve(Maze& maze);
    bool atExit(const Maze& maze) const;
    string goNorth(Maze& maze);
    string goSouth(Maze& maze);
    string goEast(Maze& maze);
    string goWest(Maze& maze);

  private:
    int row;
    int col;
};
