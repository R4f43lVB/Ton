# Ton

Ton is a terminal text editor written in pure C with no external dependencies. It puts the terminal into raw mode and draws the screen directly with VT100 escape sequences.

Current version: `0.0.1`

## Features

- Terminal in raw mode (reads key by key, with no echo and no line buffering)
- Screen rendered with VT100 escape sequences, using a write buffer to avoid flicker
- Centered welcome screen showing the editor version
- Automatic terminal size detection
- Cursor navigation across the screen

## Requirements

- A POSIX-compatible system (Linux, macOS, or WSL on Windows), since the editor uses `termios.h`, `unistd.h` and `sys/ioctl.h`
- A C compiler with C99 support (`gcc` or `clang`)
- `make` (optional, but recommended)

## Building

With `make`:

```sh
make
```

Without `make`:

```sh
cc ton.c -o ton -Wall -Wextra -pedantic -std=c99
```

To remove the generated binary:

```sh
make clean
```

## Running

```sh
./ton
```

### Key bindings

| Key | Action |
| --- | --- |
| Arrow keys (`↑` `↓` `←` `→`) | Move the cursor |
| `Home` | Go to the start of the line |
| `End` | Go to the end of the line |
| `Page Up` / `Page Down` | Go to the top / bottom of the screen |
| `Ctrl + Q` | Quit the editor |

## Project structure

```
.
├── Makefile   # Build rules (make / make clean)
├── ton.c      # Editor source code
└── ton        # Compiled binary (Linux x86-64)
```
