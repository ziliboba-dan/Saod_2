all:
	gcc -Wall -g -o tree src/bstree/*.c
	gcc -Wall -g -o tab src/hashtab/*.c
	gcc -Wall -g -o min src/bstree/exp4/*.c
	gcc -Wall -g -o exp6 src/hashtab/exp6/*.c
