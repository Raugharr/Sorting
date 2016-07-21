CC=gcc
NAME=Sorting
OBJFLD=obj/
FLAGS=-Wall -std=c99
DEBUG_FLAGS=$(FLAGS) -DDEBUG -ggdb 
RELEASE_FLAGS=$(FLAGS) -DNDEBUG -O3
COMPILE_FLAGS=$(DEBUG_FLAGS)
MAIN=main.c
DEPS=Sorting.h
OBJS=$(OBJFLD)Sorting.o

.PHONY: clean debug release 

$(OBJFLD)%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

debug: main.c $(OBJS)
	$(CC) -o $(NAME) $(MAIN) $(DEBUG_FLAGS) $(OBJFLD)*.o

release: $(OBJS)
	#COMPILE_FLAGS:= RELEASE_FLAGS
	$(CC) -o $(NAME) $(MAIN) $(RELEASE_FLAGS) $(OBJFLD)*.o

clean:
	rm -f $(OBJFLD)/*.o

