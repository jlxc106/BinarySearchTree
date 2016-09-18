#include <stdio.h>
#include <iostream>
#include "BinaryTree.h"

//Binary Search Tree - larger keys are assigned the right leaf, smaller keys are assigned the left leaf.

using namespace std;

class BinaryTree {
public:
	node *root;

	//default constructor
	BinaryTree() {
		root = NULL;
	}

	//destructor
	~BinaryTree() {
		destroy_tree(root);
	}

	/*
	Method: insert
	Parameters: none
	Description: 1) calls the private insert method if root already exists 
		2) creates the root if it doesn't exist.
	Return: void
	*/
	void insert(int key) {
		if (root != NULL)
			insert(key, root);
		else
		{
			root = new node;
			root->key_value = key;
			root->left = NULL;
			root->right = NULL;
		}
	}

	/*
	Method: search
	Parameters: user input integer key value
	Description: user inputs integer value to query in BST. Method calls the private search method to iterate through the tree.
	Return: Pointer to queried node
	*/
	node *search(int key) {
		return search(key, root);
	}

private:
	/*
	Method: destroy_tree
	Parameters: node *leaf
	Description: method is called in the destructor to destroy tree. Deletes the node once it no longer has any children. 
	Return: void
	*/
	void destroy_tree(node *leaf) {
		if (leaf != NULL)
		{
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			delete leaf;
		}
	}

	/*
	Method: insert
	Parameters: user input integer key value; node pointer leaf
	Description: Inserts the node to the BST after it compares the value of key and leaf's key value. 
		If leaf already has a left/right child, method is called again on the child node.
		If key is larger than node's key value, it is inserted as the right leaf. If smaller, it is inserted as the left leaf.
	Return: void
	*/
	void insert(int key, node *leaf) {
		if (key < leaf -> key_value)
		{
			if (leaf->left == NULL)
			{
				leaf->left = new node;
				leaf->left->key_value = key;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
			}
			else {
				insert(key, leaf->left);
			}
		}
		else if (key > leaf->key_value)
		{
			if (leaf->right == NULL)
			{
				leaf->right = new node;
				leaf->right->key_value = key;
				leaf->right->left = NULL;
				leaf->right->right = NULL;
			}
			else {
				insert(key, leaf->right);
			}
		}
	}

	/*
	Method: search
	Parameter: user input integer key, node pointer leaf
	Description: iterates through the tree to search for the node with queried integer key.
	Return: returns the pointer to a node
	*/
	node *search(int key, node *leaf) {
		if (leaf != NULL)
		{
			if (key == leaf->key_value)
			{
				return leaf;
			}
			if (key < leaf->key_value)
				return search(key, leaf->left);
			else return search(key, leaf->right);
		}
		else{
			return NULL;
		}
	}
};


int main(void)
{
	BinaryTree happytree;

	happytree.insert(100);
	happytree.insert(71);
	happytree.insert(3000);
	happytree.insert(20);
	happytree.insert(80);
	happytree.insert(200);
	happytree.insert(5000);
	cout << happytree.search(71) << endl;
}
