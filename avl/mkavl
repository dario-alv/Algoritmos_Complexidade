# makefile para a arvore AVL (Arvore de Adelson-Velskii Landis)
CC = gcc
CFLAGS = -ansi -Wall

OBJM = queue.o stack.o avl.o
HEADERS = queue.h stack.h avl.h

OBJECTS = $(OBJM) testavl.o simavl.o
EXES = tavl savl

all:	$(EXES)

tavl:	testavl.o $(OBJM)
	$(CC) $(CFLAGS) testavl.o $(OBJM) -o tavl

savl:	simavl.o $(OBJM)
	$(CC) $(CFLAGS) simavl.o $(OBJM) -o savl

$(OBJM):	$(HEADERS)

clean:
	rm -f $(OBJECTS) *~

cleanall:	clean
	rm -f $(EXES)
