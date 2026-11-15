.PHONY: all clean

all: ton

ton: ton.c
	$(CC) ./ton.c -o ton -Wall -Wextra -pedantic -std=c99

clean:
	rm -f ton