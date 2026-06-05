CC = gcc

CFLAGS = -Wall -Wextra -I./BackEnd/adt_list_folder \
                   -I./BackEnd/file_operation_folder \
                   -I./BackEnd/helper_function_folder \
                   -I./BackEnd/weapon_operation_folder \
				   -I./BackEnd/UI_folder

TARGET = elden_ring_tracker

SRC = BackEnd/main.c \
      BackEnd/adt_list_folder/adt_list.c \
      BackEnd/file_operation_folder/file_operation.c \
      BackEnd/helper_function_folder/helper.c \
      BackEnd/weapon_operation_folder/weapon.c \
	  BackEnd/UI_folder/UI.c 

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)