/*
 * File: 0-read_textfile.c
 * Auth: L0M4X.
 */
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t opens, reads, writes;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	opens = open(filename, O_RDONLY);
	reads = read(opens, buff, letters);
	writes = write(STDOUT_FILENO, buff, reads);

	if (opens == -1 || reads == -1 || writes == -1 || writes != reads)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(opens);

	return (writes);
}
