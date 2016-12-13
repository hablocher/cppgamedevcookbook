#include "CGraph.h"
#include <conio.h>

int main() {
	graph g;

	g.addVertex("teste1");

	g.addVertex("teste2");

	g.addEdge("teste1", "teste2", 10);

	_getch();

	return 0;
}