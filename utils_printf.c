#include "printf.h"

int	ft_isadigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isastar(char c)
{
	if (c == '*')
		return (1);
	return (0);
}

void	ft_completion(char *number)
{
	number[0] = '(';
	number[1] = 'n';
	number[2] = 'u';
	number[3] = 'l';
	number[4] = 'l';
	number[5] = ')';
	number[6] = '\0';
}

long	ft_strlen_digit(const char *str)
{
	long				count;
	int					i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	if (*str == '-')
		(count)--;
	return (count);
}

long	ft_strlen(const char *str)
{
	long				count;
	int					i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
