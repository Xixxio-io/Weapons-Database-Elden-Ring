CC = gcc

CFLAGS = -Wall -Wextra -I./BackEnd/include

TARGET = elden_ring_tracker

SRC = $(wildcard BackEnd/src/*.c)

OBJDIR = BackEnd/obj

OBJ = $(patsubst BackEnd/src/%.c,$(OBJDIR)/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJDIR)/%.o: BackEnd/src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)