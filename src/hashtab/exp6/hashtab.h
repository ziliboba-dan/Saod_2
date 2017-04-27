#ifndef HASHTAB_H
#define HASHTAB_H
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <inttypes.h>
#include <stdlib.h>

#define HASH_MUL 31
#define HASH_SIZE 50000

typedef unsigned int unint;

typedef struct listnode{
	char *key;
	int value;
	struct listnode *next;
} listnode;

unsigned int hashtab_hash(char *key);

void hashtab_init(listnode **hashtab);

uint32_t hashtab_hash_j(char *key, size_t len);

void hashtab_add(listnode **hashtab, char *key, int value);

listnode *hashtab_lookup(listnode **hashtab, char *key);

void hashtab_delete(listnode **hashtab, char *key);


#endif
