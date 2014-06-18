BIN   = abitaale
OBJ   = src/main.o src/display.o src/game.o src/entities.o
FLAGS = -lncurses
CC    = g++ -Wall -pedantic -Wno-long-long -O0 -ggdb

all: compile

run: compile
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ)

compile: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(FLAGS)

src/main.o: src/main.cpp src/display.h src/game.h src/entities.h
	$(CC) -c -o $@ $<

src/game.o: src/game.cpp src/game.h src/display.h src/entities.h
	$(CC) -c -o $@ $<

src/display.o: src/display.cpp src/display.h src/entities.h
	$(CC) -c -o $@ $<

src/entities.o: src/entities.cpp src/entities.h
	$(CC) -c -o $@ $<
