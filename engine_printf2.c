#include "printf.h"

void	ft_have_width_and_precision(t_list *pointer, char *number)
{
	if (pointer->type == 'p')
		pointer->width -= 2;
	pointer->count_symbol = pointer->precision - ft_strlen(number);
	if (pointer->minus)
	{
		if (pointer->int_value < 0)
		{
			write(1, "-", 1);
			(pointer->count_symbol)++;
			(pointer->length)++;
			number = &number[1];
		}
		if (pointer->type == 'p')
			ft_print_0x(pointer);
		ft_print_symbol(pointer, '0');
		ft_print_number(pointer, number);
		pointer->count_symbol = pointer->width - pointer->precision;
		if (pointer->int_value < 0)
			(pointer->count_symbol)--;
		ft_print_symbol(pointer, ' ');
	}
	else
		ft_have_width_and_precision_utility(pointer, number);
}

void	ft_have_width_and_precision_utility(t_list *pointer, char *number)
{
	if (pointer->int_value < 0 && pointer->precision >= pointer->width)
	{
		write(1, "-", 1);
		(pointer->count_symbol)++;
		(pointer->length)++;
		number = &number[1];
	}
	pointer->count_symbol = pointer->width - pointer->precision;
	if (pointer->int_value < 0)
		(pointer->count_symbol)--;
	ft_print_symbol(pointer, ' ');
	pointer->count_symbol = pointer->precision - ft_strlen(number);
	if (pointer->type == 'p')
		ft_print_0x(pointer);
	if (pointer->int_value < 0 && pointer->precision < pointer->width)
	{
		write(1, "-", 1);
		(pointer->count_symbol)++;
		(pointer->length)++;
		number = &number[1];
	}
	ft_print_symbol(pointer, '0');
	ft_print_number(pointer, number);
}

int	ft_numlen(long n)
{
	long	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

long	ft_short(char *s, long nn)
{
	s[0] = '-';
	nn *= -1;
	return (nn);
}

char	*ft_itoa(long n)
{
	char	*s;
	long	nn;
	int		i;

	i = 0;
	nn = n;
	i = ft_numlen(n);
	s = (char *)malloc(i + 1);
	if (s == NULL)
		return (NULL);
	if (nn == 0)
	{
		s[i] = '\0';
		s[0] = 0 + 48;
		return (s);
	}
	if (nn < 0)
		nn = ft_short(s, nn);
	s[i--] = '\0';
	while (nn != 0)
	{
		s[i--] = (nn % 10) + 48;
		nn /= 10;
	}
	return (s);
}
