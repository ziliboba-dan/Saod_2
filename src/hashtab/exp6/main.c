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
	FILE *n = fopen("text.txt", "r");
	FILE *a;
	a = fopen("Results.txt", "a");
	if (a == NULL) {
		return 0;
	}
	double t;
	int size = atoi(argv[1]);

	listnode *hashtab[HASH_SIZE];

	srand(time(NULL));
	int rand_node = rand() % size;

	struct str {
		char word[100];
		int value;
	} str[HASH_SIZE];
	char temp[100];

	hashtab_init(hashtab);
	int i = 0;
	while (fscanf (in, "%s", str[i].word)!= EOF) {
		hashtab_add(hashtab, str[i].word, i);
		//printf("%s\n", str[i].word);
		if (i == rand_node) {
			strcpy(temp, str[i].word);
		}
		i++;
	}

	i = 0;
	listnode *node;
	while (fscanf (n, "%s", str[i].word)!= EOF) {
	    node = hashtab_lookup(hashtab, str[i].word);
	    printf("%s,%d\n", node->key, node->value);
	    ++i;
	}
	printf("Find: %s\n", "влег");
	t = wtime();
	node = hashtab_lookup(hashtab, "влег");
	t = wtime() - t;
	printf("Время поиска: %.10f sec.\n", t);
	printf("Результат поиска: %d %s\n", node->value, node->key);
	fprintf(a, "Size: %d Hashtab: %.10f\n", size, t);
	printf("Number of collision : %d\n", count);
	fprintf(a, "Number of collision : %d\n", count);
	fclose(in);
	fclose(a);
	fclose(n);
	for(int i = 0; i < 50000; i++) {
		hashtab_delete(hashtab, str[i].word);
		i++;
    	}
	return 0;
}
