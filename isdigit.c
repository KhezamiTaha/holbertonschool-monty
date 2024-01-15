#include "monty.h"
int isDigit(char *token)
{
	int i = 1;
	if (token[0] == '-')
	{
		while (token[i] != '\0')
		{
				if (isdigit(token[i]) == 0)
					return (0);
				i++;
		}
		return (1);
	}
	else
	{
		i = 0;
		while (token[i] != '\0')
		{
				if (isdigit(token[i]) == 0)
					return (0);
				i++;
		}
		return (1);
	}

}
