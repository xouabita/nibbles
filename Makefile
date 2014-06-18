BIN   = abitaale
OBJ   = src/main.o src/display.o
FLAGS = -lncurses
CC    = g++ -Wall -pedantic -Wno-long-long -O0 -ggdb

all: compile

run: compile
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ)

compile: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(FLAGS)

src/main.o: src/main.cpp src/display.h
	$(CC) -c -o $@ $<

src/display.o: src/display.cpp src/display.h
	$(CC) -c -o $@ $<
