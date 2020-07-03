all: clean build

build: main.c fact.o
	gcc -m32 main.c fact.o -o fact

fact.o: fact.s
	nasm -g -f elf -o fact.o fact.s

clean:
	rm -f fact
	rm -f fact.o