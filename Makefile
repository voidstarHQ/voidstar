CC := clang
CFLAGS += -Wall -Wextra -std=c99 -pedantic -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Waggregate-return -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wnested-externs -Wunreachable-code
LDFLAGS := -lGL -lGLU -lm -lglut -lglfw -lGLEW
CXXFLAGS += $(CFLAGS) --std=c++1y

TARGET := miners
SRC := pixels.c
OBJ := $(SRC:.c=.o)

all: $(TARGET)

run: $(TARGET)
	./$<

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean::
	$(RM) $(OBJ)

nuke:: clean
	$(RM) $(TARGET)

distclean:: clean
	$(if $(wildcard $(TARGET)), $(RM) $(TARGET))
