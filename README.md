# Random-DumpGen
![Language](https://img.shields.io/badge/language%20-%20C-blue)
![License](https://img.shields.io/github/license/lina-torovoltas/Random-DumpGen)
![GitHub release](https://img.shields.io/github/v/release/lina-torovoltas/Random-DumpGen)
![Downloads](https://img.shields.io/github/downloads/lina-torovoltas/Random-DumpGen/total)</br>


Random dump generator in hexadecimal and octal formats.</br>
Perfect for testing, mockups, or just looking like a hacker.

## Usage

To generate a hexadecimal dump:
```bash
$ ./rdumpgen -hex
Enter the number of lines: 10
Enter the number of rows per line: 5
File dump.txt has been successfully generated in hexadecimal format

$ cat dump.txt
00000000 3A 1F A7 09 4C  # 8-digit address + N random bytes (00-FF)
00000001 00 FF 23 88 7E  # Maximum allowed lines: 4,294,967,296 (2³²)
...
```

To generate an octal dump:
```bash
$ ./rdumpgen -oct
Enter the number of lines: 10
Enter the number of rows per line: 5
File dump.txt has been successfully generated in octal format.

$ cat dump.txt
0000 12 33 07 55 60  # 4-digit address + N random 2-digit numbers (00-77)
0001 03 11 02 71 17  # Maximum allowed lines: 4,096
...
```

## Dependencies

- `make` utility for building
- `gcc` or `tcc` compiler for Linux
- `clang` and `mingw-w64` for Windows cross-compilation


## Building

1. Clone the repository and navigate to the project folder.
2. Build the project using `make`:
   ```bash
   $ make            # Builds all platforms (GCC, TCC, and Windows)
   $ make linux      # Only Linux with GCC
   $ make linux_tcc  # Only Linux with TCC
   $ make windows    # Only Windows with Clang
   ```
3. Run the compiled executable from the `build` directory:
   ```bash
   $ ./build/rdumpgen -hex       # If compiled with GCC
   $ ./build/rdumpgen_tcc -hex   # If compiled with TCC
   $ ./build/rdumpgen.exe -hex   # If running on Windows
   ```

## Contributing

Contributions are welcome!</br>
Feel free to open pull requests to improve the project.


***
Developed by <a href="https://github.com/lina-torovoltas" style="color:#ff4f00">Lina Torovoltas</a> — © 2025-2026 All rights reserved.
