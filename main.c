#include "monty.h"


int main(int argc, char *argv[])
{
    int of, size;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
    }

    of = open(argv[1], O_RDONLY);

    if (of == -1)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    size = read(of, , 10);

}
