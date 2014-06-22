BIN   = abitaale
DEBUG = src/debug
OBJ   = src/main.o src/display.o src/game.o src/entities.o src/levels.o src/gui.o
FLAGS = -lncurses
CC    = g++ -Wall -pedantic -Wno-long-long -O0 -g

all: compile

run: compile
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ)

debug: compile
	valgrind --dsymutil=yes --leak-check=full --log-file="debug.txt" ./abitaale

compile: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(FLAGS)

src/main.o: src/main.cpp src/display.h src/game.h src/entities.h src/gui.h
	$(CC) -c -o $@ $<

src/game.o: src/game.cpp src/game.h src/display.h src/entities.h
	$(CC) -c -o $@ $<

src/menu.o: src/gui.cpp src/gui.h src/display.h
	$(CC) -c -o $@ $<

src/levels.o: src/levels.cpp src/levels.h src/entities.h src/display.h
	$(CC) -c -o $@ $<

src/display.o: src/display.cpp src/display.h src/entities.h
	$(CC) -c -o $@ $<

src/entities.o: src/entities.cpp src/entities.h
	$(CC) -c -o $@ $<
