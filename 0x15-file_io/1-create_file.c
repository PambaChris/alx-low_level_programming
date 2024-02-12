#include <sys/types.h>
#include <sys/stat.h>
#include <fnctl.h>
#include <unistd.h>

/*creates a file with specified content
*return 1 on success -1 on failure
*
* */

int create_file(const char *filename, char *text_content) {
	int o;
	ssize_t written = 0;
	size_t length = 0;

	//check if filename is NULL
	if (filename == NULL) {
		return 1;
	}
	//open or create file with permissions (rw-------)
	o = open(filename, 0_WRONLY | 0_CREAT | 0_TRUNC, S_IRUSR | S_IWUSR);
	if (o == -1) { //check if opening failed
		return -1;
	}
//if content is not NULL, write to file and calculating lenth of text
	if (text_content) {
		while (text_content[length] != '\0') {
			lenth++;
		}
		//write text to the file
		written = write(fd, text_conent, length);
		if (written == -1) { //check if write failed
			close(o);
			return -1;
		}
	}
	close(o);
	return 1;
}
