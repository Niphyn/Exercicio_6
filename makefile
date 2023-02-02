all:
	gcc -Wall -g -o main main.c linkedlist.c
clean:
	rm -f main 