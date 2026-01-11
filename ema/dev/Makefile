# Makefile to make the build fast and easy
# Compiler (compatible with -I option)
CC = gcc

all: run

run: build/main.o build/contactor.o build/manager.o build/emails.o build/names.o build/memory.o build/user.o
	$(CC) -Iinclude \
	build/main.o \
	build/contactor.o \
	build/manager.o \
	build/emails.o \
	build/names.o \
	build/memory.o \
	build/user.o \
	-o bin/app

build/main.o: src/main.c
	$(CC) -Iinclude -c src/main.c -o build/main.o

build/contactor.o: src/contactor.c include/contactor.h
	$(CC) -Iinclude -c src/contactor.c -o build/contactor.o

build/manager.o: src/manager.c include/manager.h
	$(CC) -Iinclude -c src/manager.c -o build/manager.o

build/emails.o: src/emails.c include/emails.h
	$(CC) -Iinclude -c src/emails.c -o build/emails.o

build/names.o: src/names.c include/names.h
	$(CC) -Iinclude -c src/names.c -o build/names.o

build/memory.o: src/memory.c include/memory.h
	$(CC) -Iinclude -c src/memory.c -o build/memory.o

build/user.o: src/user.c include/user.h
	$(CC) -Iinclude -c src/user.c -o build/user.o

clean:
	rm -f build/* bin/* saves/*