# Presentation

This project aims to provide a variety of beautiful maze generation
algorithms under a small and simple header-only library.
To start creating cool mazes as the one below, just include
the header *maze_generators.h* and have a look on this doc !

<p align="center">
  <img src="https://github.com/ismaelbelghiti/maze-generators-cpp/blob/master/doc_images/maze_example.png?raw=true" alt="Maze Example"/>
</p>

# Output Format

All the functions of this library, except *convert_to_block_maze*, return a
*vector< vector< int > >* representing the generated maze.
Noting *res* this result, the following conventions are used:
- there is a wall between cell (iLine, iCol) and cell (iLine, iCol + 1) 
when *(res[iLine][iCol] & 1) == 0*,
 - there is a wall between cell (iLine, iCol) and cell (iLine + 1, iCol) 
when *(res[iLine][iCol] & 2) == 0*.
Remark: The walls seperating the grid cells  from outside are implicit, only
the ones separating two celles of the grid are explicited. Please also note 
that operator & has not priority on operator == (that is why we use parentheses 
in the previous expressions).