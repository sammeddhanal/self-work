#include <stdio.h>

int main() {
    // Step 1: Create a 4-byte integer with a known value
    // 0x12345678 in hexadecimal:
    //   12 = most significant byte (MSB)
    //   78 = least significant byte (LSB)
    unsigned int num = 0x12345678;

    // Step 2: Create a pointer to the first byte of 'num'
    // We use 'unsigned char *' because each byte is 8 bits
    unsigned char *bytePtr = (unsigned char*)&num;

    // Step 3: Print the memory representation of 'num'
    // This helps us visualize the order of bytes in memory
    printf("Memory representation of num (hex bytes): ");
    for (int i = 0; i < sizeof(num); i++) {
        printf("%02x ", bytePtr[i]);
    }
    printf("\n");

    // Step 4: Determine endianness
    // Little Endian: LSB stored first -> bytePtr[0] = 0x78
    // Big Endian: MSB stored first -> bytePtr[0] = 0x12
    if (bytePtr[0] == 0x78) {
        printf("System is Little Endian.\n");
        printf("Explanation: Least significant byte (0x78) is stored first in memory.\n");
    } else if (bytePtr[0] == 0x12) {
        printf("System is Big Endian.\n");
        printf("Explanation: Most significant byte (0x12) is stored first in memory.\n");
    } else {
        printf("Unknown Endianness.\n");
    }

    return 0;
}


/*
   # Compiler
CC = gcc

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TEST_DIR = tests

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TARGET = endian_detect

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Default build
.PHONY: build
build: $(TARGET)

# Debug build
.PHONY: debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build
.PHONY: release
release: CFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

# Link target
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@

# Compile objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run tests
.PHONY: test
test: build
	$(CC) -I$(INCLUDE_DIR) $(TEST_DIR)/test_endian.c -o $(BUILD_DIR)/test_endian
	$(BUILD_DIR)/test_endian
	*/
