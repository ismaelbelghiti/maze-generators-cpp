# Presentation

This project aims to provide a variety of beautiful maze generation
algorithms under a small and simple header-only library.
To start creating cool mazes as the one below, just include
the header *maze_generators.h* and have a look on this doc:
- [Features](#features)
- [Output format](#output_format)
- [A complete example](#)
- [Detailed descriptions](#detailed_descriptions)

<p align="center">
  <img src="https://github.com/ismaelbelghiti/maze-generators-cpp/blob/master/doc_images/maze_example.png?raw=true" alt="Maze Example"/>
</p>

<a name="features"></a>
# Features

Here is the list of all functions proposed by the library.
You can click on a function name to be redirected
to the detailed description (below on this page).


For the generation of random connected acyclic mazes:
- *vector< vector< int > > [rand_maze](#rand_maze)(int nbLines, int nbCols);*

<a name="output_format"></a>
# Output format

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

<a name="complete_example"></a>
# A complete example

```cpp
#include <iostream>
#include "maze_generators.h"
using namespace std;
 
int main() {
	int nbLines = 8, nbCols = 9;
 
	vector< vector<int> > maze = rand_maze(nbLines,nbCols);
 
	for(int iLine = 0; iLine < nbLines; iLine++) {
		for(int iCol = 0; iCol < nbCols; iCol++) {
			cout << maze[iLine][iCol] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
```

This programs displays
```
1 1 3 1 1 1 3 1 0 
2 2 3 3 0 2 2 1 2 
1 2 2 1 2 3 2 2 2 
1 3 3 0 0 2 1 1 0 
2 0 3 0 1 2 2 2 2 
2 3 0 3 1 1 1 3 2 
3 3 0 3 3 2 3 0 2 
0 0 1 0 0 0 0 1 0
```

that corresponds to the following maze:
<p align="center">
  <img src="https://github.com/ismaelbelghiti/maze-generators-cpp/blob/master/doc_images/example_output.png?raw=true" alt="rand_maze example"/>
</p>

<a name="detailed_descriptions"></a>
# Detailed descriptions

<a name="rand_maze"></a>
## rand_maze

```cpp
vector< vector<int> > rand_maze(int nbLines, int nbCols);
```

Draw a connected acyclic maze uniformly, using Wilson's algorithm. Can be
quite slow for big dimensions.

<p align="center">
  <img src="https://github.com/ismaelbelghiti/maze-generators-cpp/blob/master/doc_images/rand_maze_example.png?raw=true" alt="rand_maze example"/>
</p>




