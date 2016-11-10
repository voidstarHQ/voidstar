CC := clang++
CXX := clang++
CFLAGS += -Wall -Wextra -std=c99 -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Waggregate-return -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wnested-externs -Wunreachable-code -g3
LDFLAGS := -lGL -lGLU -lm -lglut -lglfw -lGLEW
CXXFLAGS += -Wall -Wextra -std=c++1y
CXXFLAGS += -g3

TARGET := miners
# SRC := pixels.c
SRC := points.c shaders.cc
OBJ := $(SRC:.c=.o)

all: $(TARGET)

run: $(TARGET)
	./$<

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean::
	$(if $(wildcard $(OBJ)), $(RM) $(OBJ))

nuke:: clean
	$(RM) $(TARGET)

distclean:: clean
	$(if $(wildcard $(TARGET)), $(RM) $(TARGET))
