// Initialize the node with a value and pointers
// to left child
// and rigth child
#include "CTree.h"

Binary_Tree::Binary_Tree()
{
	root = NULL;
}

Binary_Tree::~Binary_Tree()
{
	destroy_tree();
}

void Binary_Tree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->rigth);
		delete leaf;

	}
}

void Binary_Tree::insert(string key, node *leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->rigth = NULL;
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->rigth != NULL)
			insert(key, leaf->rigth);
		else
		{
			leaf->rigth = new node;
			leaf->rigth->key_value = key;
			leaf->rigth->left = NULL;
			leaf->rigth->rigth = NULL;
		}
	}
}

node *Binary_Tree::search(string key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->rigth);
	}
	else return NULL;
}

void Binary_Tree::insert(string key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->rigth = NULL;
	}
}

node *Binary_Tree::search(string key)
{
	return search(key, root);
}

void Binary_Tree::destroy_tree()
{
	destroy_tree(root);
}