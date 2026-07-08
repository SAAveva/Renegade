SRC = $(wildcard source/*.c)
OBJ = $(patsubst source/%.c,build/%.o,$(SRC))

all: renegade

renegade: $(OBJ)
	gcc $(OBJ) -o renegade -Iinclude -lSDL2

build/%.o: source/%.c
	gcc -Wall -Wextra -O3 -c $< -o $@

clean: 
	rm build/*.o renegade
