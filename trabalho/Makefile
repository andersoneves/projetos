CC=gcc 
CFALGS= -Wall -ansi -pedantic 
all: lib
	clear
	$(CC) $(CFALGS) -o prog  teste.c  jogo.a
lib:
	$(CC)  -c jogo.c -o jogo.o
	ar rv jogo.a  jogo.o
clean: 
	clear
	rm -f prog
exec:
	./prog