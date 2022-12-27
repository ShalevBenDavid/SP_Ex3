.PHONY = all clean
#Defining Macros
AR = ar
CC = gcc
FLAGS = -Wall -g

all: isort txtfind

#Creating Programs
isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o
txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

#Creating Objects
isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c
txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

clean:
	rm -f *.o isort txtfind