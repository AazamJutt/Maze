#include "creature.h"
 #include "maze.h"
#include <iostream>
using namespace std;


/*You can always change Maze number of ROWS,COLS
  ,EXIT_ROW,EXIT_COL and MAZE LAYOUT in maze.h, nothing is hard coded*/ 

 void SolveMaze(int x, int y)/*x,y are location of Creature*/ {
     Maze m;
     cout << m << endl;
     cout << "Creature is at position: " << x << ',' << y << endl;
     Creature c(x, y);
     cout << "Path: " << c.solve(m) << endl << endl;
     cout << m << endl;
 }

int main() {
    SolveMaze(4,4);//Creature is at location 4,4
    return 0;
}