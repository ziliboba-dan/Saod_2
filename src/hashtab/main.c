#include "hashtab.h"
#include <sys/time.h>
#include <time.h>

int count = 0; 

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char *argv[])
{
	FILE *in = fopen("text.txt", "r");
	FILE *a;
	a = fopen("Results.txt", "a");
	if (a == NULL) {
		return 0;
	}
	char *key = malloc(sizeof(char)*100);
	unsigned int value;
	double t;
	int size = atoi(argv[1]);
	listnode *hashtab[100];
	listnode *node;
	srand(time(NULL));
	int rand_node = rand() % size;

	hashtab_init(hashtab);

	for (int i = 1; i <= size; i++) {
		char *ftemp = malloc(sizeof(char)*100);
		fscanf(in, "%s\n", ftemp);
		value = hashtab_hash(key);
		hashtab_add(hashtab, key, value);
		if (i == rand_node) {
           		strcpy(key, ftemp);
   		 }
	}
	printf("Find: %s\n", key);
	t = wtime();
	node = hashtab_lookup(hashtab, key);
	t = wtime() - t;
	printf("Время поиска: %.10f sec.\n", t);
	printf("Number of collision : %d\n", count);
	printf("Результат поиска: %d %s\n", node->value, node->key);
	fprintf(a, "Size: %d Hashtab: %.10f\n", size, t);
	fclose(in);
	fclose(a);

	return 0;
}
