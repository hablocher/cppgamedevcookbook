#ifndef CTREE_H
#define CTREE_H
#include <string>

using namespace std;

struct node
{
	string key_value;
	node *left;
	node *rigth;
};

class Binary_Tree
{
public:
	Binary_Tree();
	~Binary_Tree();

	void insert(string key);
	node *search(string key);
	void destroy_tree();

private:
	void destroy_tree(node *leaf);
	void insert(string key, node *leaf);
	node *search(string key, node *leaf);

	node *root;
};


#endif // !CTREE_H

