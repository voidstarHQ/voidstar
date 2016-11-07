CFLAGS += -Wall -Wextra -pedantic
CXXFLAGS += $(CFLAGS) --std=c++0x

all: miners.cc
	clang $(CFLAGS) -o miners -lGL -lGLU -lm -lglut -lglfw -lGLEW miners.c
	./miners

clean:
	$(if $(wildcard miners), rm miners)
