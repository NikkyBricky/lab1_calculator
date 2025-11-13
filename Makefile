.PHONY: run clean all
CFLAGS = -Wall -Wextra
ARGS = 41 \+ 33 111 \- 8 22 \* 5 221 \% 111 100 \+ 13 -k 2
all: main
main.o: main.c
	gcc -c main.c $(CFLAGS)
checks.o: checks.c
	gcc -c checks.c $(CFLAGS)
calc.o: calc.c
	gcc -c calc.c $(CFLAGS)
decoder.o: decoder.c
	gcc -c decoder.c $(CFLAGS)
main: main.o checks.o calc.o decoder.o
	gcc main.o calc.o checks.o decoder.o -o main
clean:
	rm *.o main
run: main
	./main $(ARGS) 
