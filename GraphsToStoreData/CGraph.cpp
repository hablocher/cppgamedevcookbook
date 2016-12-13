#include "CGraph.h"

void graph::addVertex(const string &name)
{
	vmap::iterator itr = work.begin();
	itr = work.find(name);
	if (itr == work.end())
	{
		vertex *v;
		v = new vertex(name);
		work[name] = v;
		return;
	}
	cout << "\nVertex already exists!";
}

void graph::addEdge(const string& from, const string& to, double cost)
{
	vertex *f = (work.find(from)->second);
	vertex *t = (work.find(to)->second);
	pair<int, vertex *> edge = make_pair(cost, t);
	f->adj.push_back(edge);
}