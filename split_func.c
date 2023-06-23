#include "monty.h"

char **split_line(char *line, buf_struct *bf)
{
    char* token;
    int i = 0;

    /* Split line into tokens*/
    token = strtok(line, " \t");
    while (token != NULL && i < 2)
    {
        bf->tok_cmd[i] = token;
        token = strtok(NULL, " \t");
        i++;
    }
    /*add NULL into end tok_cmd*/
    bf->tok_cmd[i] = NULL;

    if (bf->tok_cmd[0] == NULL)
		return (NULL);

    if (strncmp(bf->tok_cmd[0], "#", 1) == 0)
		bf->tok_cmd[0] = "nop";
    
    return (bf->tok_cmd);
}


int digits_only(char* str)
{
    int i = 0;

    if (str == NULL)
        return (0);

    if (str[i] == '-' || str[i] == '+')
        i++; /* Skip the optional sign */

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
