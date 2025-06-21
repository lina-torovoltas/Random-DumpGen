# Random-DumpGen
![Language](https://img.shields.io/badge/language%20-%20C-blue)
![License](https://img.shields.io/github/license/lina-torovoltas/Random-DumpGen)
![GitHub release](https://img.shields.io/github/v/release/lina-torovoltas/Random-DumpGen)
![Downloads](https://img.shields.io/github/downloads/lina-torovoltas/Random-DumpGen/total)</br>

Random dump generator in hexadecimal and octal format.


## Usage

To generate a hexadecimal dump:
```bash
  $ ./rdumpgen -hex
  Enter the number of lines: 10
  Enter the number of rows per line: 5
  File dump.txt has been successfully generated in hexadecimal format.

  $ cat dump.txt
  00000000 3A 1F A7 09 4C
  00000001 00 FF 23 88 7E
  ...
```

Each line begins with an 8-digit hexadecimal address.</br>
Followed by N random bytes (`00`–`FF`) in uppercase hex.</br>
Maximum allowed lines: **4,294,967,296 (2³²)**</br>

To generate a octal dump:

```bash
  $ ./rdumpgen -oct
  Enter the number of lines: 10
  Enter the number of rows per line: 5
  File dump.txt has been successfully generated in octal format.

  $ cat dump.txt
  0000 12 33 07 55 60
  0001 03 11 02 71 17
  ...
```

Each line starts with a 4-digit octal address.</br>
Followed by N random values in octal (`00`–`77`).</br>
Maximum allowed lines: **4096**</br>


## Dependencies

- `make` utility for building
- `gcc` utility for compiling C


## Building

1. Clone the repository.
2. Navigate to the project folder.
3. Build using `make`:
    ```bash
    $ make
    ```
4. Run:
    ```bash
    $ ./build/dumpgen -hex
    ```


## Contributing

Contributions are welcome!</br>
Feel free to open pull requests to improve the project.


## Author

Developed by <a href="https://github.com/lina-torovoltas" style="color:#ff4f00">Lina Torovoltas</a> — © 2025 All rights reserved.
