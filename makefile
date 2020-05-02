CC = gcc
CFLAGS = -O0 -g3
OBJECTS = main.o linked_list.o

project: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o $@
main.o: main.c linked_list.h
linked_list.o: linked_list.c linked_list.h

.PHONEY: clean clean_all
clean:
	-rm project ${OBJECTS}
clean_all:
	-rm projects ${OBJECTS} *~
