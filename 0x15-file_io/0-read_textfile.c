#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//checks if filename is NULL if so returns 
ssize_t read_textfile(const char *filename, size_t letters) {
	if (filename == NULL) {
		return 0;
	}

	int fd = open(filename, 0_RDONLY);
	if (fd == -1) {
		return 0;
	}

	char *buffer = (char *)malloc(letters * sizeof(char));
	if (buffer == NULL) {
		close(fd);
		return 0;
	}

	ssize_t bytesRead = read (fd, buffer, letters);
	if (bytesRead == -1) {
	close(fd);
	free(buffer);
	return 0;
	}
	
	ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten == -1 || bytesWritten != bytesRead) {
		close(fd);
		free(buffer);
		return 0;
	}

	close(fd);
	free(buffer);
	return bytesWritten;
}

int main() {
	//example use 
	ssize_t result = read_textfile("example.txt")
	if (result == 0) {
		//Error handled
	} else {
		//success
	}
	return 0;
}


