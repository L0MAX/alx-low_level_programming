#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check97 - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check98 - checks that file_from exists and can be read
 * @check: checks if true of false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check98(ssize_t check, char *file, int fdes_from, int fdes_toen)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fdes_from != -1)
			close(fdes_from);
		if (fdes_toen != -1)
			close(fdes_toen);
		exit(98);
	}
}

/**
 * check99 - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @file: file_to name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check99(ssize_t check, char *file, int fdes_from, int fdes_toen)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fdes_from != -1)
			close(fdes_from);
		if (fdes_toen != -1)
			close(fdes_toen);
		exit(99);
	}
}

/**
 * check100 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check100(int check, int fdes)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fdes %d\n", fdes);
		exit(100);
	}
}
/**
 * main - opies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fdes_from, fdes_toen, close_toen, closeon_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	check97(argc);
	fdes_from = open(argv[1], O_RDONLY);
	check98((ssize_t)fdes_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fdes_toen = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check99((ssize_t)fdes_toen, argv[2], fdes_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fdes_from, buffer, 1024);
		check98(lenr, argv[1], fdes_from, fdes_toen);
		lenw = write(fdes_toen, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		check99(lenw, argv[2], fdes_from, fdes_toen);
	}
	close_toen = close(fdes_toen);
	closeon_from = close(fdes_from);
	check100(close_toen, fdes_toen);
	check100(closeon_from, fdes_from);
	return (0);
}
