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




void readLinesFromFile(char *filename, buf_struct *bf)
{
    char* line = NULL;
    FILE *of;
    int i = 0;
    size_t  lineLength = 0;
    ssize_t bytesRead;

    of = fopen(filename, "r");

    if (of == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((bytesRead = getline(&line, &lineLength, of)) != -1)
    {
        bf->list_cmd[i] = line;
        i++;
    }

    free(line);
    fclose(of);
}



int main(int argc, char *argv[])
{
    char *filename;
    buf_struct *bf;

	bf = make_struct(argv);

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
    }
    filename = argv[1];
    readLinesFromFile(filename, bf);
    execute_fun(bf);
    
    return (0);
}