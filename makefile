CC=gcc
EXEC=sha1

build: main.c message.c
	$(CC) $^ -o $(EXEC) -Wall
