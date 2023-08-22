# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Link object files to create the executable
all: main.h main.c printf.c
	$(CC) $(CFLAGS) *.c -o printf
