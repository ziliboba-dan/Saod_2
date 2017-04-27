#ifndef BSTREE_H
#define BSTREE_H
#include <stdlib.h>
#include <string.h>

typedef struct bstree {
	char *key;
	int value;
	struct bstree *left;
	struct bstree *right;
} bstree;

bstree *bstree_create(char *key, int value);
void bstree_add(bstree *tree, char *key, int value);
<<<<<<< HEAD
bstree *bstree_lookup(bstree *tree, char *key);
=======
bstree *bstree_lookup(bstree *tree, int value);
>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
bstree *bstree_min(bstree *tree);
bstree *bstree_max(bstree *tree);

#endif
