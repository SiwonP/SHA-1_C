CC=gcc
EXEC=sha1

build: main.c message.c hash.c
	$(CC) $^ -o $(EXEC) -Wall
