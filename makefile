SRC = $(wildcard source/*.c)
OBJ = $(patsubst source/%.c,build/%.o,$(SRC))

all: renegade

renegade: $(OBJ)
	gcc $(OBJ) -o renegade -lSDL2

build/%.o: source/%.c
	gcc -Wall -Wextra -O3 -Iinclude -c $< -o $@

clean: 
	rm build/*.o renegade
