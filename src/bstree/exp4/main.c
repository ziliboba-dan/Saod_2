#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <sys/time.h>
#include <time.h>

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
	FILE *d;	
	d = fopen("textexp4#2.txt", "r");
	if (d == NULL) {
		return 0;
	}
	FILE *a;
	a = fopen("Results.txt", "a");
	if (a == NULL) {
		return 0;
	}

	bstree *tree;

	int random = rand() % size;
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
		}
		if (i == random) {
			strcpy(temp, str[i].word);
		}
	}
	printf("Min:\n");
	t = wtime();
	bstree *test2 = bstree_min(tree);
	t = wtime() - t;
	printf("Word: %s\n", test2->key);
	fprintf(a, "Size: %d Min: %.10f\n", size, t);
	printf("Time: %.10f\n", t);
	fclose(a);
	fclose(d);
	return 0;
}
