//
// Created by XXX on YYY.
//

#include "creature.h"

ostream& operator<<(ostream& out, const Creature& creature) { return out; }

Creature::Creature(int row, int col) : row(row), col(col) {}

bool Creature::atExit(const Maze& maze) const {
    //checks if creature is at exit location or not
    return row == maze.getExitRow() && col == maze.getExitColumn();
}

string Creature::solve(Maze& maze) {
    string path="",temp="";

    int r = row, c = col;//used for BACKTRACKING

    //Base Case if Creature is atExit
    if (atExit(maze)) {
        maze.markAsPath(row, col);
        return "";
    }

    // Check if maze[x][y] is clear
    if (maze.isClear(row, col)) {
        // Check if the current block is already visited
        if (maze.isVisited(row,col))
            return "";

        // mark x, y as part of solution path// mark x, y as visited
        maze.markAsVisited(row, col);

        
       /* Move towards EAST */
        path = goEast(maze);
        path.append(solve(maze));//append path returned by revursion
        if (atExit(maze)) {
            maze.markAsPath(r, c);
            return path;
        } else {//BackTrack
            row = r;
            col = c;
        }
        
        /* If moving towards EAST didn't give any
        solution then move towards WEST*/
        path = goWest(maze);
        path.append(solve(maze));
        if (atExit(maze)) {
            maze.markAsPath(r, c);
            return path;
        } else {//BackTrack
            row = r;
            col = c;
        }

        /* If moving towards WEST didn't give any
        solution then move towards NORTH*/
        path = goNorth(maze);
        path.append(solve(maze));
        if (atExit(maze)) {
            maze.markAsPath(r, c);
            return path;
        } else {//BackTrack
            row = r;
            col = c;
        }

        /* If moving towards NORTH didn't give any
        solution then move towards SOUTH*/
        path = goSouth(maze);
        path.append(solve(maze));
        if (atExit(maze)) {
            maze.markAsPath(r, c);
            return path;
        } else {//BackTrack
            row = r;
            col = c;
        }
    }
    return "";//If no dirction gave any solution return null string
}
string Creature::goNorth(Maze& maze) { 
    if (row > 0) {
        row = row - 1;
        return "N";
    }
    return "";
}

string Creature::goWest(Maze& maze) {
    if (col > 0) {
        col = col - 1;
        return "W";
    }
    return "";
}

string Creature::goEast(Maze& maze) {
    if (col < maze.getWidth()-1) {
        col = col + 1;
        return "E";
    }
    return "";
}
string Creature::goSouth(Maze& maze) {
    if (row < maze.getHeight() - 1) {
        row = row + 1;
        return "S";
    }
    return "";
}