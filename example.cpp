#include <iostream>
#include "maze_generators.h"
using namespace std;

void display_maze(vector< vector<int> > maze) {
	int nbLines = (int)maze.size(), nbCols = (int)maze[0].size();
	for(int iLine = 0; iLine < nbLines; iLine++) {
		for(int iCol = 0; iCol < nbCols; iCol++ ) {
			cout << ".";
			if(iCol < nbCols-1) {
				if(!(maze[iLine][iCol] & 1)) {
					cout << "#";
				} else {
					cout << ".";
				}
			}
		}
		cout << endl;
		if(iLine < nbLines-1) {
			for(int iCol = 0; iCol < nbCols; iCol++ ) {
				if(!(maze[iLine][iCol] & 2)) {
					cout << "#";
				} else {
					cout << ".";
				}
				if(iCol < nbCols - 1) {
					cout << "#";
				}
			}
			cout << endl;
		}
	}
}


void rand_maze_example() {
	cout << "rand_maze_example:" << endl;
	int nbLines = 7, nbCols = 12;
	vector< vector<int> > maze = rand_maze(nbLines, nbCols);
	display_maze(maze);
	cout << endl << endl;
}


int main() {
	rand_maze_example();
	return 0;
}
