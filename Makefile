CC := clang
CFLAGS += -Wall -Wextra
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
