#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <time.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

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
	for (int i = 0; i < size; i++) {
		char *temp = malloc(sizeof(char) * 100);
        	fscanf(d, "%s\n", temp); 

		if (i == 0) {
			tree = bstree_create(temp, size / 2);
		}
		else {
			bstree_add(tree, temp, rand());
		}
		if (i == random) {
			strcpy(word, temp);
		}
		//memset(word, 0, 100);
	}
	bstree *test;
	double t;
	if (ptr == 0) {
		printf("Word which we find: %s %d\n", word, random);
		printf("Lookup:\n");
		t = wtime();
		test = bstree_lookup(tree, random);
		t = wtime() - t;
		printf("Word: %s\n", test->key);
		fprintf(a, "Size: %d Lookup: %.10f\n", size, t);
	}
	if (ptr1 == 0) {
		printf("Min:\n");
		t = wtime();
		test = bstree_min(tree);
		t = wtime() - t;
		printf("Word: %s\n", test->key);
		fprintf(a, "Size: %d Min: %.10f\n", size, t);
	}

	printf("Time: %.10f\n", t);
	fclose(a);
	fclose(d);
	return 0;
}
