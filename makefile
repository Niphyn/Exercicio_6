all:
	gcc -Wall -g -o main main.c linkedlist.c
clean:
	rm -f main 
run:
	./main
val:
	valgrind --leak-check=full --show-leak-kinds=all ./main