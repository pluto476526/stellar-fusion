# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -g -I./inc -std=c11 -D_GNU_SOURCE -D_POSIX_C_SOURCE=200809L
LDFLAGS := -lm


# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Target
TARGET  := $(BIN_DIR)/stellar-fusion

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Ensure directories exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Link
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run
run: $(TARGET) $(TARGET)

# Debug build
debug: CFLAGS  += -DDEBUG -Og -fsanitize=address,undefined
debug: LDFLAGS += -fsanitize=address,undefined
debug: clean all

# Profile build
profile: CFLAGS  += -pg
profile: LDFLAGS += -pg
profile: clean all

.PHONY: all clean run debug profile
