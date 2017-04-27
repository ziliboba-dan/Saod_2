#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <string.h>


bstree * bstree_create(char * key, int value) 
{
	bstree * node = NULL;
	node = malloc(sizeof(bstree));
	if (node) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
<<<<<<< HEAD
	}
	else{
		return NULL;
	}
	return node;
}

void  bstree_add(bstree * tree, char * key, int value)
{
	bstree * parent = NULL;
	//bstree * tmp = tree;

	while(tree != NULL) {
		parent = tree;
		if(strcmp(key, tree->key) < 0) {
		    tree = tree->left;
		}
		else if(strcmp(key, tree->key) > 0) {
			tree = tree->right;
		}
		else
		    return; 
	} 
	bstree * node = bstree_create(key, value);
	if (strcmp(key, parent->key) < 0) {
		parent->left = node;
	}
	else {
		parent->right = node;
	}

}

bstree * bstree_lookup(bstree * tree, char * key) 
{
	while(tree){
		if (strcmp(key, tree->key) == 0){
			return tree;
		}
		else if(strcmp(key, tree->key) < 0){
			tree = tree->left;
			continue;
		}
		else if(strcmp(key, tree->key) > 0){
			tree = tree->right;
			continue;
=======
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
>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
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
<<<<<<< HEAD
=======
		printf("%s\n", tree->key);
>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
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
