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
		//printf("%s\n", node->key);
		return node;
	}
	
	return NULL;
}

void bstree_add(bstree *tree, char *key, int value)
{	
	bstree *parent, *node;
	if (tree == NULL) {
		return ;
	}
	
	for (parent = tree; tree != NULL; ) {
		parent = tree;
		if (value < tree->value) {
			tree = tree->left;
		} else if (value > tree->value) {
			tree = tree->right;
		} else {
			return;
		}
	}
	node = bstree_create(key, value);
	if (value < tree->value) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

bstree *bstree_lookup(bstree *tree, int value)
{	
	
	while (tree != NULL) {
		if (value == tree->value) {
			return tree;
		} else if (value < tree->value) {
			tree = tree->left;
		} else {
			tree = tree->right;
		}
	}
	return tree;
}
			
bstree *bstree_min(bstree *tree)
{
	if (tree == NULL) {
		return NULL;
	}
	while (tree->left != NULL) {
		printf("%s\n", tree->key);
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree)
{
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right != NULL) {
		tree = tree->right;
	}
	return tree;
}
