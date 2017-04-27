#include "hashtab.h"

extern int count;

unint hashtab_hash(char * key) {
	unint h = 0;
	char * p;

	for(p = key;*p != '\0';p++)
			h = h * HASH_MUL + (unint)*p;
	return h % HASH_SIZE;
}

uint32_t hashtab_hash_j(char *key, size_t len) {

	uint32_t hash, i;
	for(hash = i = 0; i < len; ++i) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash <<15);
	return hash % HASH_SIZE;
}

void hashtab_init(listnode **hashtab)
{
	for (int i = 0; i < 100; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(listnode **hashtab,char *key, int value) {
	listnode *node;
	//int index = hashtab_hash(key);
   	uint32_t index = hashtab_hash_j(key, strlen(key));
	node = malloc(sizeof(*node));
	if(node) {
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;

	}
}

listnode *hashtab_lookup(listnode **hashtab, char * key) {
	
	listnode * node;
	//int index = hashtab_hash(key);
	uint32_t index = hashtab_hash_j(key, strlen(key));
	for(node = hashtab[index]; node != NULL; node = node->next) {
		if(strcmp(node->key, key) == 0) {
			//printf("Number of collision : %d\n", count);
			return node;
		}
		//printf("Number of collision : %d\n", count);
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
