#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * make_struct - Set values for struct.
 * @argv: Argument list.
 * Return: Struct for buffers.
 */
buf_struct *make_struct(char *argv[])
{
	static buf_struct bf;

	bf.argv = argv;
	memset(bf.list_cmd, 0, sizeof(bf.list_cmd));
	memset(bf.tok_cmd, 0, sizeof(bf.tok_cmd));

	return (&bf);
}


/**
 * readLinesFromFile - Reads lines from a file and stores them in bf->list_cmd.
 * @filename: The name of the file to read.
 * @bf: Pointer to the buf_struct object.
 */

void readLinesFromFile(char *filename, buf_struct *bf)
{
	char *line = NULL;
	FILE *of;
	int i = 0;
	size_t  lineLength = 0;
	ssize_t bytesRead = 1;

	of = fopen(filename, "r");

	if (of == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (i < 1000 && bytesRead > 0)
	{
		bytesRead = getline(&line, &lineLength, of);
		if (bytesRead > 0)
		{
			bf->list_cmd[i] = strdup(line);
			i++;
		}
	}
	/*bf->list_cmd[i] = NULL;*/
	free(line);
	fclose(of);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or an exit status on failure.
 */

int main(int argc, char *argv[])
{
	char *filename;
	buf_struct *bf;
	int i = 0;

	bf = make_struct(argv);

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	readLinesFromFile(filename, bf);

	execute_fun(bf);

	/*Free allocated memory*/
	for (i = 0; bf->list_cmd[i]; i++)
		free(bf->list_cmd[i]);

	return (0);
}
