CC=gcc 
CFALGS= -Wall -ansi -pedantic -o --cflags 

all: lib
	clear
	$(CC) $(CFALGS) prog  teste.c  node-c.a
lib:
	$(CC)  -c node-c.c -o node-c.o
	ar rv node-c.a  node-c.o
clean: 
	clear
	rm -f prog
exec:
	./prog