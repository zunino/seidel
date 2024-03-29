LIB_DESC   = Seidel - Simple SDL Wrapper
LIB_NAME   = seidel
LIB_VER    = 0.12.1
LIB_FILE   = bin/$(LIB_NAME)-$(LIB_VER).a

CC         = g++
CFLAGS     = -std=c++17 -c -Wall -g -D_REENTRANT -Iinclude
LDFLAGS    = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2_ttf

UNITS      = Seidel SDLError SDL Window Texture Sprite Clock Random Vector CollisionBox Utils Text Audio Timer
TEST_UNITS = tests random-test vector-test collision-test utils-test texture-test

OBJ       := $(addsuffix .o, $(addprefix bin/, $(UNITS)))
OBJ_TEST  := $(addsuffix .o, $(addprefix bin-test/, $(TEST_UNITS)))

SRC       := $(addsuffix .cpp, $(addprefix src/, $(UNITS)))
SRC_TEST  := $(addsuffix .cpp, $(addprefix src-test/, $(TEST_UNITS)))

DIST_DIR  = dist/seidel-$(LIB_VER)

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

run-tests: tests
	bin-test/tests

setup:
	@mkdir -p bin bin-test 2> /dev/null

dist: seidel
	@mkdir -p $(DIST_DIR)/lib
	@echo Copying include files to $(DIST_DIR)/include
	@cp -r include/ $(DIST_DIR)
	@echo Copying $(LIB_FILE) to $(DIST_DIR)/lib
	@cp $(LIB_FILE) $(DIST_DIR)/lib

debug:
	@echo "SRC:      $(SRC)"
	@echo "SRC_TEST: $(SRC_TEST)"
	@echo "OBJ:      $(OBJ)"
	@echo "OBJ_TEST: $(OBJ_TEST)"
	@echo "LIB_FILE: $(LIB_FILE)"
	@echo "DIST_DIR: $(DIST_DIR)"

clean:
	rm -f bin/*.o
	rm -f bin/*.a
	rm -f bin-test/*.o
	rm -f bin-test/sample
	rm -f bin-test/tests

