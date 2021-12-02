#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to newly allocated space in
 * memory, which contains a copy of given string
 * @str: string
 * Return: array of character
 */
char *_strdup(char *str)
{
	unsigned int i, size = strlen(str);
	char *ch;

	if (str == NULL)
		return (NULL);

	ch = malloc(sizeof(char) * size + 1);
	if (ch == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ch[i] = str[i];
	ch[i] = '\0';
	return (ch);
}
