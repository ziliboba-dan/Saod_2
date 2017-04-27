#include "hashtab.h"

extern int count;

unsigned int hashtab_hash(char *key)
{
	unsigned int value = 0;

	for (int i = 0; key[i] != '\0'; i++) {
		if (key[i] == '\n') {
			continue;
		}	
		value += key[i];		
	}

	return value % 100;
}

void hashtab_init(listnode **hashtab)
{
	for (int i = 0; i < 100; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(listnode **hashtab, char *key, int value)
{
	listnode *node;

	int index = hashtab_hash(key);

	node = malloc(sizeof(*node));

	if (node != NULL) {
		node->value = value;
		node->key = key;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

listnode *hashtab_lookup(listnode **hashtab, char *key)
{
	int index;
	listnode *node;

	index = hashtab_hash(key);

	for (node = hashtab[index]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0) {
			return node;
		}
		count++;
	}
	return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
	int index;
	listnode *p, *prev = NULL;

	index = hashtab_hash(key);

	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL) {
				hashtab[index] = p->next;
			} else {
				prev->next = p->next;
			}
			free(p);
			return;
		}
		prev = p;
	}
}

