#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int size = atoi(argv[1]);
	char *Name = argv[2];
	FILE *d;	
	d = fopen("text.txt", "r");
	if (d == NULL) {
		return 0;
	}
	FILE *a;
	a = fopen("Results.txt", "a");
	if (a == NULL) {
		return 0;
	}

	bstree *tree;
	int ptr, ptr1; 
	
	ptr = strcmp("look", Name);
	ptr1 = strcmp("min", Name);

	int random = rand() % size;
	char word[100];
	clock_t time;
	for (int i = 0; i < size; i++) {
		char *temp = malloc(sizeof(char)*100);
        	fscanf(d, "%s\n", temp);

		if (i == 0) {
			tree =bstree_create(temp, i);
		}
		else {
			bstree_add(tree, temp, i);
		}
		if (i == random) {
			strcpy(word, temp);
		}
		//memset(word, 0, 100);
	}
	bstree *test;
	if (ptr == 0) {
		printf("Word which we find: %s %d\n", word, random);
		printf("Lookup:\n");
		time = clock();
		test = bstree_lookup(tree, word);
		time = clock() - time;
		printf("Word: %s\n", test->key);
		fprintf(a, "Size: %d Lookup: %.10f\n", size, (double)time/CLOCKS_PER_SEC);
	}
	if (ptr1 == 0) {
		printf("Min:\n");
		time = clock();
		test = bstree_min(tree);
		time = clock() - time;
		printf("Word: %s\n", test->key);
		fprintf(a, "Size: %d Min: %.10f\n", size, (double)time/CLOCKS_PER_SEC);
	}

	printf("Time: %.10f\n", (double)time/CLOCKS_PER_SEC);
	fclose(a);
	fclose(d);
	return 0;
}
