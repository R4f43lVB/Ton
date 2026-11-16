#ifndef TON_H
#define TON_H

#include <termios.h>

#define CTRL_KEY(k) ((k) & 0x1f)

/*
This enum handles key presses that send escape sequences.
It starts with `ARROW_LEFT = 1000`
*/
enum editorKey {
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,
    DEL_KEY,
    HOME_KEY,
    END_KEY,
    PAGE_UP,
    PAGE_DOWN
};


/*
Structure containing the configuration for the cursor, the window and the original terminal attributes
obtained when the program first runs.

- `cx`, `cy`: the values for the cursor's x and y positions;
- `screenRows`, `screenCols`: the number of rows and columns in the terminal;
- `orig_termios`: the original attributes of the terminal, obtained via <termios.h>.
*/
struct editorConfig {
    int cx, cy;
    int screenRows;
    int screenCols;
    struct termios orig_termios;
};

/*
Cleans STDOUT before printing the error message for `s` via `perror`.
Exits the program with code 1.
*/
void die(const char *s);

/*
Disables Raw Mode by setting the terminal attributes back to their original values
*/
void disableRawMode(void);

/*
Sets the terminal to Raw Mode by changing its attributes.
*/
void enableRawMode(void);

/*
Checks whether the pressed key returns an escape sequence and, if so, which one.
If the pressed key doesn't send an escape sequence, returns the ASCII value for the pressed key.
*/
int editorReadKey(void);

/*
Uses `winsize` (`sys/ioctl.h`) to get the window's dimensions and stores them in `rows` and `cols`
*/
int getWindowSize(int *rows, int *cols);

/*
Custom definition for dynamic string type (currently only supports appending).
- `b`: Content of the string
- `len`: Size of the string
*/
typedef struct a_buf {
    char *b;
    int len;
} abuf;

/*
This acts as a constructor for `abuf`
setting the `b` pointer to `NULL` and its length to 0.
*/
#define ABUF_INIT {NULL, 0}

/*
Appends the content of `s` to `ab.b`.
Uses `realloc()` to increase the amount of memory allocated for `b`
and `memcpy()` to append `len` bytes of `s` to `ab.b`.
*/ 
void abAppend(abuf *ab, const char *s, int len);

/*
Works as a destructor for `abuf`. freeing the allocated memory.
*/
void abFree(abuf *ab);

/*
Draws the welcome screen, and rows
*/
void editorDrawRows(abuf *ab);

/*
Handles the refreshing of the contents of the screen
and sets the cursor to the position indicated by `E.cx` and `E.cy`
*/
void editorRefreshScreen(void);

/*
Updates the values stored in `E.cx` and `E.cy` based on `key`
*/
void editorMoveCursor(int key);

/*
Handles the output based on the pressed key (including escape sequences)
*/
void editorProcessKeypress(void);

/*
Initiates Ton
*/
void initEditor(void);

int main(void);

#endif