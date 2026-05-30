SRC = src/main.c
BUILD_DIR = build

TARGET_LINUX     = rdumpgen
TARGET_LINUX_TCC = rdumpgen_tcc
TARGET_WINDOWS   = rdumpgen.exe

CFLAGS_GCC   = -O3 -Wall -Wextra -s -fdata-sections -ffunction-sections -Wl,--gc-sections,-s
CFLAGS_TCC   = -O2 -Wall -Wextra
CFLAGS_CLANG = -target x86_64-pc-windows-gnu -O3 -fdata-sections -ffunction-sections -Wl,--gc-sections

.PHONY: all linux linux_tcc windows clean

all: linux linux_tcc windows

linux:
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling for Linux with GCC..."
	@gcc $(CFLAGS_GCC) $(SRC) -o $(BUILD_DIR)/$(TARGET_LINUX)
	@echo "Build finished: $(BUILD_DIR)/$(TARGET_LINUX)"

linux_tcc:
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling for Linux with TCC..."
	@tcc $(CFLAGS_TCC) $(SRC) -o $(BUILD_DIR)/$(TARGET_LINUX_TCC)
	@echo "Build finished: $(BUILD_DIR)/$(TARGET_LINUX_TCC)"

windows:
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling for Windows..."
	@clang $(CFLAGS_CLANG) $(SRC) -o $(BUILD_DIR)/$(TARGET_WINDOWS)
	@x86_64-w64-mingw32-strip --strip-all $(BUILD_DIR)/$(TARGET_WINDOWS)
	@echo "Build finished: $(BUILD_DIR)/$(TARGET_WINDOWS)"

clean:
	@rm -rf $(BUILD_DIR)
