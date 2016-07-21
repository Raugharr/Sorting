CC=gcc
NAME=Sorting
OBJFLD=obj/
FLAGS=-Wall -std=c99
DEBUG_FLAGS=$(FLAGS) -DDEBUG -ggdb 
RELEASE_FLAGS=$(FLAGS) -DNDEBUG -O3
COMPILE_FLAGS=$(DEBUG_FLAGS)
MAIN=Tests.c
DEPS=InsertSortTest.h ShellSortTest.h QuickSortTest.h MergeSortTest.h HeapSortTest.h
OBJS=$(OBJFLD)InsertSortTest.o $(OBJFLD)ShellSortTest.o $(OBJFLD)QuickSortTest.o $(OBJFLD)MergeSortTest.o $(OBJFLD)HeapSortTest.o
LIB=-lcheck -lm -lpthread -lrt

.PHONY: clean debug release 

$(OBJFLD)%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

debug: $(MAIN) $(OBJS)
	$(CC) -o $(NAME) $(MAIN) $(DEBUG_FLAGS) $(OBJFLD)*.o ../$(OBJFLD)*.o $(LIB)

release: $(MAIN) $(OBJS)
	$(CC) -o $(NAME) $(MAIN) $(RELEASE_FLAGS) $(OBJFLD)*.o $(LIB)

clean:
	rm -f $(OBJFLD)/*.o

