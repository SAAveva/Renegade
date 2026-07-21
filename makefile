SRC = $(wildcard source/*.c)
OBJ = $(patsubst source/%.c,build/%.o,$(SRC))
BUILD_DIR = build/
PROGRAM_NAME = renegade

all: renegade

run: renegade
	./$(BUILD_DIR)/$(PROGRAM_NAME)

renegade: $(OBJ)
	gcc $(OBJ) -o $(BUILD_DIR)/$(PROGRAM_NAME) -lSDL2

build/%.o: source/%.c | build
	gcc -Wall -Wextra -O3 -Iinclude -c $< -o $@

build:
	mkdir -p $(BUILD_DIR)

clean: 
	rm -r $(BUILD_DIR)
