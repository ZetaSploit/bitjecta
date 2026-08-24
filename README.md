# bitjecta

A minimal C++ binary file parser and hexadecimal dumper.

`bitjecta` reads a file in binary mode and prints its contents as hexadecimal byte values. The project is currently focused on low-level file inspection and is intended as a foundation for experimenting with binary formats and reverse engineering.

## Features

* Opens files in binary mode.
* Reads the entire file into memory.
* Displays file contents byte-by-byte in hexadecimal.
* Formats output into 16 bytes per line.
* Accepts the input filename as a command-line argument.
* Uses C++17 filesystem functionality for file validation.

## Building

### Requirements

* A C++ compiler with C++17 support
* `make` is optional

Using `g++`:

```bash
g++ -std=c++17 -O2 bitjecta.cc -o bitjecta
```

## Usage

```bash
./bitjecta <file>
```

For example:

```bash
./bitjecta /bin/ls
```

Example output:

```text
7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
03 00 3e 00 01 00 00 00 ...
```

## How It Works

The program:

1. Takes a filename from `argv[1]`.
2. Opens the file using `std::ifstream` in binary mode.
3. Determines the file size.
4. Allocates a buffer large enough to hold the file.
5. Reads the file into memory.
6. Iterates over every byte.
7. Prints each byte as a two-digit hexadecimal value.
8. Inserts a newline after every 16 bytes.

The core parsing routine is:

```cpp
void fparse(const std::string& file_name)
```

## Project Status

**Early development**

The current implementation is intentionally simple. Future versions may expand from raw hexadecimal dumping into actual binary-format parsing.

Possible directions include:

* ELF parsing
* PE parsing
* Mach-O parsing
* Binary headers
* Sections and segments
* Endianness detection
* Symbol tables
* String extraction
* Disassembly
* Reverse-engineering utilities

## Motivation

`bitjecta` is being developed as a low-level C++ project for understanding how binary files are represented and structured at the byte level.

The goal is to progressively move from:

```text
raw bytes
    ↓
binary structures
    ↓
executable formats
    ↓
disassembly
    ↓
reverse engineering
```

## License

License information has not been added yet.

