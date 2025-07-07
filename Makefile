# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -O2 -fopenmp
DEBUGFLAGS = -g -DDEBUG

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET  = $(BIN_DIR)/openmp_sort
DEBUG_TARGET = $(BIN_DIR)/openmp_sort_debug

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEBUG_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%_debug.o, $(SRCS))

.PHONY: all debug clean run rundebug rebuild

# Default build
all: $(TARGET)

# Debug build
debug: $(DEBUG_TARGET)

# Linking
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(DEBUG_TARGET): $(DEBUG_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ $^

# Compile source to object
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%_debug.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Create directories
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Run
run: $(TARGET)
	./$(TARGET)

rundebug: $(DEBUG_TARGET)
	./$(DEBUG_TARGET)

# Clean
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/openmp_sort $(BIN_DIR)/openmp_sort_debug

# Rebuild
rebuild: clean all
