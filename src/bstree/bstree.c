#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"


bstree *bstree_create(char *key, int value)
{
	bstree *node;

	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	return NULL;
}

bstree *bstree_add(bstree *tree, char *key, int value)
{	
	if (tree == NULL) {
		tree = bstree_create(key, value);
		return tree;
	}
	
	int cmp;
	cmp = strcmp(key, tree->key);
	bstree *root;
	root = tree;

	if (cmp == 0) {
		tree->value = value;
		return tree;
	} else if (cmp < 0) {
		tree->left = bstree_add(tree->left, key, value);
	} else {
		tree->right = bstree_add(tree->right, key, value);
	}
	return root;
}

bstree *bstree_lookup(bstree *tree, char *key)
{
	
	if (tree == NULL) {
		return NULL;
	}
	
    	int cmp = strcmp(key, tree->key);
   
	if (cmp == 0) {
		return tree;
	} else if (cmp < 0) {
		return bstree_lookup(tree->left, key);
	} else {
		return bstree_lookup(tree->right, key);
	}
}
			
bstree *bstree_min(bstree *tree)
{
	if (tree == NULL) {
		return NULL;
	}
	while (tree->left !=NULL) {
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree)
{
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right !=NULL) {
		tree = tree->right;
	}
	return tree;
}
