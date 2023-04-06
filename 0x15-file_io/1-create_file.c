#include "main.h"
/**
 * create_file -creates an array of chars, and initializes
 *
 * @text_content: is a NULL terminated string to write to the file
 * @filename: is the name of the file to create
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int opens, writes, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	opens = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writes = write(opens, text_content, len);

	if (opens == -1 || writes == -1)
		return (-1);

	close(opens);

	return (1);
}
