#include "maze.h"
#include <iostream>
#include <sstream>


ostream& operator<<(ostream& out, const Maze& maze) {
    for (int row = 0; row < maze.height; row++) {

        for (int col = 0; col < maze.width; col++) {

            out << maze.field[row][col];
        }
        out << endl;
    }
    out << endl;

    return out;
}


Maze::Maze() : field{{0}}, width{COLS}, height{ROWS}, exitRow{EXIT_ROW}, exitColumn{EXIT_COL} {

     for (int row = 0; row < height; row++) {

        for (int col = 0; col < width; col++) {

            field[row][col] = MAZE[row][col];
        }
    }

}

int Maze::getExitRow() const { return exitRow; }

int Maze::getExitColumn() const { return exitColumn; }

int Maze::getWidth() const { return width; }

int Maze::getHeight() const { return height; }

bool Maze::isClear(int row, int col) const { return field[row][col] == CLEAR; }

bool Maze::isVisited(int row, int col) const { return field[row][col] == VISITED; }

void Maze::markAsPath(int row, int col) { field[row][col] = PATH; }

void Maze::markAsVisited(int row, int col) { field[row][col] = VISITED; }
