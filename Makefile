CC      = g++
CFLAGS  = -std=c++1y -c -Wall -g -I/usr/include/SDL2 -D_REENTRANT -I./include
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2_ttf

UNITS      = Seidel SDLError SDL Window Texture Sprite Clock
TEST_UNITS = sample

SRC      := $(addsuffix .cpp, $(addprefix src/, $(UNITS)))
SRC_TEST := $(addsuffix .cpp, $(addprefix src-test/, $(TEST_UNITS)))

OBJ      := $(addsuffix .o, $(addprefix bin/, $(UNITS)))
OBJ_TEST := $(addsuffix .o, $(addprefix bin-test/, $(TEST_UNITS)))

sample: $(OBJ) $(OBJ_TEST)
	$(CC) -o sample $^ $(LDFLAGS)

bin/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

bin-test/%.o: src-test/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

debug:
	@echo $(SRC)
	@echo $(SRC_TEST)
	@echo $(OBJ)
	@echo $(OBJ_TEST)

clean:
	rm -f bin/*.o
	rm -f bin-test/*.o
	rm -f src/*.o
	rm -f src-test/*.o
	rm -f ./sample