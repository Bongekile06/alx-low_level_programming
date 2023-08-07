#include "main.h"
#include <stdlib.h>

/**
 * read_txtfile - Read txt file & prnt to STDOUT.
 * @filename: Txt file being read.
 * @letters: Num of letters to be read.
 *
 * Return: The actual num of bytes read and prntd. 0 if the function fails
 *         or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
