BIN   = abitaale
DEBUG = src/debug
OBJ   = src/main.o src/display.o src/entities.o src/levels.o src/gui.o src/player.o
FLAGS = -lncurses
CC    = g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -g

all: compile doc

run: compile
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJ)
	rm -rf doc

debug: compile
	valgrind --dsymutil=yes --leak-check=full --log-file="debug.txt" ./abitaale

doc:
	cd src; \
	doxygen Doxyfile
	cd ..;
	mv src/html ./doc

compile: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(FLAGS)

src/main.o: src/main.cpp src/display.h src/entities.h src/gui.h
	$(CC) -c -o $@ $<

src/menu.o: src/gui.cpp src/gui.h src/display.h
	$(CC) -c -o $@ $<

src/levels.o: src/levels.cpp src/levels.h src/entities.h src/display.h
	$(CC) -c -o $@ $<

src/player.o: src/player.cpp src/player.h src/entities.h src/display.h
	$(CC) -c -o $@ $<

src/display.o: src/display.cpp src/display.h src/entities.h
	$(CC) -c -o $@ $<

src/entities.o: src/entities.cpp src/entities.h
	$(CC) -c -o $@ $<
