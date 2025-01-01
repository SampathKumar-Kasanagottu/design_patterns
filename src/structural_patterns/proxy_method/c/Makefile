# Makefile for compiling with_pattern.c and without_pattern.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall
#CFLAGS = -Wall -g #uncomment for debugging

# Source files
SRC_WITH_PATTERN = with_pattern.c
SRC_WITHOUT_PATTERN = without_pattern.c

# Target executables
TARGET_WITH_PATTERN = with_pattern
TARGET_WITHOUT_PATTERN = without_pattern

# Default rule to build both programs
all: $(TARGET_WITH_PATTERN) $(TARGET_WITHOUT_PATTERN)

# Rule for creating the with_pattern executable
$(TARGET_WITH_PATTERN): $(SRC_WITH_PATTERN)
	$(CC) $(CFLAGS) $(SRC_WITH_PATTERN) -o $(TARGET_WITH_PATTERN)

# Rule for creating the without_pattern executable
$(TARGET_WITHOUT_PATTERN): $(SRC_WITHOUT_PATTERN)
	$(CC) $(CFLAGS) $(SRC_WITHOUT_PATTERN) -o $(TARGET_WITHOUT_PATTERN)

# Run both programs
run: $(TARGET_WITH_PATTERN) $(TARGET_WITHOUT_PATTERN)
	@echo "Running with_pattern..."
	./$(TARGET_WITH_PATTERN)
	@echo "Running without_pattern..."
	./$(TARGET_WITHOUT_PATTERN)

# Clean rule to remove all compiled files
clean:
	rm -f $(TARGET_WITH_PATTERN) $(TARGET_WITHOUT_PATTERN)
