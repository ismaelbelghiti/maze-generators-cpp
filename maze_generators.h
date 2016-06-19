#ifndef MAZE_GENERATORS_H
#define MAZE_GENERATORS_H

#include "combinatorial-generators-cpp/combinatorial_generators.h"

/*
  This function aims to explicit the edges of the underlying grid-graph in 
  order to use a subgraph generation algorithm and then convert back its
  result to a maze with the function maze_from_edges defined just after.
*/
std::vector< std::pair<int,int> > maze_edges(int nbLines, int nbCols) {
	std::vector< std::pair<int,int> > resEdges;
	for(int iLine = 0; iLine < nbLines; iLine++) {
		for(int iCol = 0; iCol < nbCols; iCol++) {
			int idNode = iLine * nbCols + iCol;
			int idRightNeigh = idNode + 1;
			int idBottomNeigh = idNode + nbCols;
			if(iCol + 1 < nbCols) {
				resEdges.push_back(std::make_pair(idNode, idRightNeigh));
			}
			if(iLine + 1 < nbLines) {
				resEdges.push_back(std::make_pair(idNode, idBottomNeigh));
			}
		}
	}
	return resEdges;
}


/*
  This function is used to convert back a grid-graph subset of 
  edges to a maze. Noting res the result, it can be read as follows:
  - there is a wall between cell (iLine, iCol) and cell (iLine, iCol + 1) 
    when (res[iLine][iCol] & 1) == 0,
  - there is a wall between cell (iLine, iCol) and cell (iLine + 1, iCol) 
    when (res[iLine][iCol] & 2) == 0.
  Remark: The walls seperating the grid cells  from outside are implicit, only
  the ones separating two celles of the grid are explicited. Please also note 
  that operator & has not priority on operator == (that is why we use parentheses 
  in the previous expressions).
*/
std::vector< std::vector<int> > maze_from_edges(
	int nbLines, int nbCols, std::vector< std::pair<int,int> > edges) {
	const int RIGHT = 1, BOTTOM = 2;
	std::vector< std::vector<int> > maze(nbLines, std::vector<int>(nbCols, 0));
	for(int iEdge = 0; iEdge < (int)edges.size(); iEdge++) {
		int idNode1 = edges[iEdge].first;
		int idNode2 = edges[iEdge].second;
		if(idNode1 > idNode2) {
			std::swap(idNode1, idNode2);
		}
		int iLine = idNode1 / nbCols;
		int iCol  = idNode1 % nbCols;
		if(idNode2 - idNode1 == 1 && nbCols > 1) { // right 
			maze[iLine][iCol] += RIGHT;
		} else { // bottom 
			maze[iLine][iCol] += BOTTOM;
		}
	}
	return maze;
}


/*
  This function is the equivalent of rand_tree for mazes.
*/
std::vector< std::vector<int> > rand_maze(int nbLines, int nbCols) {
	std::vector< std::pair<int,int> > treeEdges = rand_spanning_tree(
		nbLines * nbCols, maze_edges(nbLines, nbCols));
	return maze_from_edges(nbLines, nbCols, treeEdges);
}



#endif /* MAZE_GENERATORS_H */
