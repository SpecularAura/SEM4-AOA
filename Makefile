CC=gcc
FLAGS=-g
MAIN=main.c
_SRC=sortingalgorithms.c
OBJ=$(patsubst %.c, %.o,$(_SRC))
BINY=$(patsubst %.c,%,$(_SRC))
all: main $(BINY)

main: $(BINY)
	$(CC) $(FLAGS) -I . $(MAIN) $(OBJ) -o $(patsubst %.c,%,$(MAIN))
	
$(BINY):
	$(CC) -c $(FLAGS) $(_SRC)