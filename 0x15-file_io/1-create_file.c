#include "main.h"

/**
 * _myexit - Exits the shell with a given exit status.
 * @info: Structure containing potential arguments. Used to maintain
 *        a constant function prototype.
 *
 * Return: If info->argv[0] is not "exit", returns 0. Otherwise,
 *         returns the exit status specified by info->argv[1].
 */

int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
