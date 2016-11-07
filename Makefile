CFLAGS += -Wall -Wextra -pedantic
CXXFLAGS += $(CFLAGS) --std=c++0x

all:
	clang $(CFLAGS) -o miners -lGL -lGLU -lm -lglut -lglfw -lGLEW draw.c
	./miners

clean:
	$(if $(wildcard miners), rm miners)
