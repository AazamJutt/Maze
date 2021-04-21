//
// Created by XXX on YYY.
//

#pragma once

#include <ostream>

using namespace std;

enum CELL { CLEAR=' ', WALL='X', PATH='*', VISITED='+' };

class Maze {
    friend ostream& operator<<(ostream& out, const Maze& maze);

  public:
    explicit Maze();
    bool isClear(int row, int col) const;
    bool isVisited(int row, int col) const;
    void markAsPath(int row, int col);
    void markAsVisited(int row, int col);
    int getWidth() const;
    int getHeight() const;
    int getExitRow() const;
    int getExitColumn() const;

  private:
    static const int ROWS = 7;
    static const int COLS = 20;
    static const int EXIT_ROW = 0;
    static const int EXIT_COL = 18;
    const char MAZE[ROWS][COLS] = {//Maze can be changed any time
        WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
        WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  CLEAR, WALL,

        WALL,  CLEAR, CLEAR, CLEAR, CLEAR, CLEAR, WALL,  CLEAR, CLEAR, CLEAR,
        CLEAR, CLEAR, CLEAR, CLEAR, WALL,  WALL,  WALL,  WALL,  CLEAR, WALL,

        WALL,  CLEAR, WALL,  WALL,  WALL,  WALL,  WALL,  CLEAR, WALL,  WALL,
        WALL,  WALL,  WALL,  CLEAR, CLEAR, CLEAR, WALL,  WALL,  CLEAR, WALL,

        WALL,  CLEAR, WALL,  WALL,  WALL,  WALL,  WALL,  CLEAR, WALL,  WALL,
        WALL,  WALL,  WALL,  WALL,  WALL,  CLEAR, WALL,  WALL,  CLEAR, WALL,

        WALL,  CLEAR, WALL,  CLEAR, CLEAR, CLEAR, CLEAR, CLEAR, CLEAR, CLEAR,
        CLEAR, CLEAR, CLEAR, WALL,  WALL,  CLEAR, WALL,  WALL,  CLEAR, WALL,

        WALL,  CLEAR, WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
        WALL,  WALL,  CLEAR, WALL,  WALL,  CLEAR, CLEAR, CLEAR, CLEAR, WALL,

        WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,
        WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL,  WALL};

    char field[ROWS][COLS];
    int width;
    int height;
    int exitRow;
    int exitColumn;
};
