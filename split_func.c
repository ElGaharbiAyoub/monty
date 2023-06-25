#include "monty.h"
/**
 * split_line - Splits a line into tokens and stores them in bf->tok_cmd.
 * @line: The input line to split.
 * @bf: Pointer to the buf_struct object.
 *
 * Return: The array of tokens stored in bf->tok_cmd,
 *  or NULL if no tokens found.
 */
char **split_line(char *line, buf_struct *bf)
{
	char *token;
	int i = 0;
	char delem[] = " \t\n";

	/* Split line into tokens*/
	token = strtok(line, delem);
	while (token != NULL && i < 2)
	{
		bf->tok_cmd[i] = token;
		token = strtok(NULL, delem);
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

/**
 * digits_only - Checks if a string contains only digits.
 * @str: The input string to check.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int digits_only(char *str)
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

/**
 * is_empty_line - Checks if a line is empty
 * (consists only of whitespace characters).
 * @line: The line to be checked.
 *
 * Return: 1 if the line is empty, 0 otherwise.
 */
int is_empty_line(char *line)
{
	while (*line)
	{
		if (!isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}
