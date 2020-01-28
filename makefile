CC=gcc
CFLAGS=-Wall -Wextra -fno-stack-protector # special constant that adds compiler flags to gcc command automatically

SRCS := $(wildcard *.c) # all files with .c extension is stored in the SRCS variable
BINS := $(SRCS:%.c=%) # all binary files will have their filenames match their .c counterparts

# Inspired by http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

all: one two three

one: program1.o
	$(CC) -o program1 program1.o -lm

two: program2.o
	$(CC) -o program2 program2.o -lm

three: program3.o
	$(CC) -o program3 program3.o -lm

clean:
	rm -rvf *.o ${BINS}
