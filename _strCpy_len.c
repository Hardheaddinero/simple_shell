#include "shell.h"
/**
 * _strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}
#include "shell.h"

/**
 * _strcmp - Compare Two String
 * @s1: String 1
 * @s2: String 2
 * Return: 0 If Identical Otherwise How Much Different
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1 = 0, len2 = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (len1 != len2)
		return (1);

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - Check if Alphabetic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
