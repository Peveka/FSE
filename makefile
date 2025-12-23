CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Iinc
SRC_DIR = src
INC_DIR = inc
OUT_DIR = out

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/file_io.c $(SRC_DIR)/number_operations.c $(SRC_DIR)/mem_handle.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

EXECUTABLE = app.exe

all: $(EXECUTABLE)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.exe *.o

.PHONY: all clean