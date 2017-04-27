#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <sys/time.h>
#include <time.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

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
<<<<<<< HEAD
	double t;
	char temp[100];
	struct str {
		char word[50];
		int value;
	} str[60000];
		
	for (int i = 0; i < size; i++) {
        	fscanf(d, "%s\n", str[i].word);

		if (i == 0) {
			tree =bstree_create(str[i].word, i);
		}
		else {
			bstree_add(tree, str[i].word, i);
=======
	char word[100];
	for (int i = 0; i < size; i++) {
		char *temp = malloc(sizeof(char) * 100);
        	fscanf(d, "%s\n", temp); 

		if (i == 0) {
			tree = bstree_create(temp, size / 2);
		}
		else {
			bstree_add(tree, temp, rand());
>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
		}
		if (i == random) {
			strcpy(temp, str[i].word);
		}
	}
<<<<<<< HEAD
=======
	bstree *test;
	double t;
>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
	if (ptr == 0) {
		printf("Word which we find: %s %d\n", temp, random);
		printf("Lookup:\n");
		t = wtime();
<<<<<<< HEAD
		bstree *test = bstree_lookup(tree, temp);
=======
		test = bstree_lookup(tree, random);
>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
		t = wtime() - t;
		printf("Word: %s\n", test->key);
		fprintf(a, "Size: %d Lookup: %.10f\n", size, t);
	}
	if (ptr1 == 0) {
		printf("Min:\n");
		t = wtime();
<<<<<<< HEAD
		bstree *test2 = bstree_min(tree);
		t = wtime() - t;
		printf("Word: %s\n", test2->key);
		fprintf(a, "Size: %d Min: %.10f\n", size, t);
	}
=======
		test = bstree_min(tree);
		t = wtime() - t;
		printf("Word: %s\n", test->key);
		fprintf(a, "Size: %d Min: %.10f\n", size, t);
	}

>>>>>>> acf9633e602aea6ef998c5930960fa5258ba3339
	printf("Time: %.10f\n", t);
	fclose(a);
	fclose(d);
	return 0;
}
