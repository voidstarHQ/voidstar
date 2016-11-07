CFLAGS += -Wall -Werror -Wextra -pedantic --std=c++0x

all: miners.cc
	clang++ $(CFLAGS) -o miners -lGL -lGLU -lm -lglut -lglfw -lGLEW miners.cc
	./miners
