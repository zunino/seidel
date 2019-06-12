LIB_DESC   = Seidel - Simple SDL Wrapper
LIB_NAME   = seidel
LIB_VER    = 0.9.0
LIB_FILE   = bin/$(LIB_NAME)-$(LIB_VER).a

CC         = g++
CFLAGS     = -std=c++17 -c -Wall -g -D_REENTRANT -Iinclude
LDFLAGS    = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2_ttf

UNITS      = Seidel SDLError SDL Window Texture Sprite Clock Random Vector CollisionBox Utils Text
TEST_UNITS = tests random-test vector-test collision-test utils-test texture-test

OBJ       := $(addsuffix .o, $(addprefix bin/, $(UNITS)))
OBJ_TEST  := $(addsuffix .o, $(addprefix bin-test/, $(TEST_UNITS)))

SRC       := $(addsuffix .cpp, $(addprefix src/, $(UNITS)))
SRC_TEST  := $(addsuffix .cpp, $(addprefix src-test/, $(TEST_UNITS)))

seidel: setup $(LIB_FILE)

$(LIB_FILE): $(OBJ)
	ar rcs $@ $(OBJ)

sample: seidel bin-test/sample.o
	$(CC) -o bin-test/sample bin-test/sample.o $(LIB_FILE) $(LDFLAGS)

tests: seidel $(OBJ_TEST)
	$(CC) -o bin-test/tests $(OBJ_TEST) $(LIB_FILE) $(LDFLAGS)

bin/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

bin-test/%.o: src-test/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

setup:
	@mkdir -p bin bin-test 2> /dev/null

debug:
	@echo "SRC:      $(SRC)"
	@echo "SRC_TEST: $(SRC_TEST)"
	@echo "OBJ:      $(OBJ)"
	@echo "OBJ_TEST: $(OBJ_TEST)"
	@echo "LIB_FILE: $(LIB_FILE)"

clean:
	rm -f bin/*.o
	rm -f bin/*.a
	rm -f bin-test/*.o
	rm -f bin-test/sample
	rm -f bin-test/tests

