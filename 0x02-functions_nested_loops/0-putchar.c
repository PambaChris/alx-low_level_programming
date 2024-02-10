#include "unistd.h"
int _putchar(char c) {
	return write(1, &c, 1);
}

int main(void) {
	char *str = "_putchar";
	while (*str) {
		_putchar(*str++);
	}

	_putchar('\n');
	return (0);
}

