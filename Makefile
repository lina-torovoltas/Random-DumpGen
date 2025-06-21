CC = gcc
CFLAGS = -O3 -Wall -Wextra
SRC = src/main.c
BUILD_DIR = build
TARGET = $(BUILD_DIR)/rdumpgen

.PHONY: all clean

all: $(TARGET)

$(BUILD_DIR):
	@echo "Creating build directory..."
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) | $(BUILD_DIR)
	@echo "Compiling project..."
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Build finished."

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Build directory removed."