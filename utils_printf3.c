#include "printf.h"//4 функции

char	*ft_itoa_to16_if0(char *result)
{
	result = malloc(2);
	if (result)
	{
		result[0] = '0';
		result[1] = '\0';
	}
	return (result);
}

void	ft_itoa_to16_if_positive(char *result, long count, \
long long n, char *characters)
{
	long long	remain;

	result[count] = '\0';
	count--;
	while (n)
	{
		remain = n % 16;
		if (remain >= 0 && remain <= 9)
			result[count] = remain + 48;
		else if (remain >= 10 && remain <= 15)
		{
			remain %= 10;
			result[count] = characters[remain];
		}
		count--;
		n /= 16;
	}
}

char	*ft_itoa_to16(long long n, char *characters)
{
	char		*result;
	long		count;
	long long	copy;

	result = NULL;
	count = 0;
	copy = n;
	if (n == 0)
		return (ft_itoa_to16_if0(result));
	while (copy)
	{
		copy /= 16;
		count++;
	}
	result = malloc(count + 1);
	if (result)
		ft_itoa_to16_if_positive(result, count, n, characters);
	return (result);
}

void	ft_print_0x(t_list *pointer)
{
	write(1, "0x", 2);
	pointer->length += 2;
}

void	ft_update_str(t_list *pointer)
{
	pointer->type = '0';
	pointer->width = 0;
	pointer->minus = 0;
	pointer->zero = 0;
	pointer->precision = 0;
	pointer->int_value = 0;
	pointer->precision_have = 0;
	pointer->count_symbol = 0;
	pointer->have_space = 0;
	pointer->free = 0;
}
