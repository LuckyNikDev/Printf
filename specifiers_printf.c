#include "printf.h"

void	ft_print_percent(t_list *pointer)
{
	char	*number;

	if (pointer->width > 0)
	{
		number = malloc(2);
		number[0] = '%';
		number[1] = '\0';
		ft_have_only_width(pointer, number);
		free(number);
	}
	else
	{
		write (1, "%", 1);
		(pointer->length)++;
	}
}

void	ft_print_p(t_list *pointer, va_list arg)
{
	char	*number;
	char	characters[7];

	ft_print_p_utility(characters, "abcdef");
	pointer->type = 'p';
	pointer->int_value = va_arg(arg, unsigned long);
	number = ft_itoa_to16(pointer->int_value, characters);
	ft_print_d_i_u_xX(pointer, number);
	free(number);
}

void	ft_print_c(t_list *pointer, va_list arg)
{
	char	character;

	character = (char)va_arg(arg, int);
	if (pointer->minus)
	{
		write(1, &character, 1);
		(pointer->length)++;
		pointer->count_symbol = --(pointer->width);
		ft_print_symbol(pointer, ' ');
	}
	else
	{
		pointer->count_symbol = --(pointer->width);
		ft_print_symbol(pointer, ' ');
		write(1, &character, 1);
		(pointer->length)++;
	}
}

void	ft_print_s(t_list *pointer, va_list arg)
{
	char	*number;

	pointer->type = 's';
	number = va_arg(arg, char *);
	if (pointer->precision < 0)
	{
		pointer->precision = 0;
		pointer->precision_have = 0;
	}
	if (number == NULL)
	{
		pointer->free = 1;
		number = malloc(7);
		ft_completion(number);
		if (pointer->precision >= 6)
			pointer->precision_have = 0;
	}
	if (pointer->precision == 0 && pointer->precision_have == 1 \
	&& *number == '\0')
		pointer->precision_have = 0;
	ft_print_characters(pointer, number);
	if (pointer->free)
		free(number);
}

void	ft_print_d_i(t_list *pointer, va_list arg)
{
	char	*number;

	if (pointer->have_space)
	{
		write(1, " ", 1);
		if (pointer->width)
			pointer->width -= 1;
	}
	pointer->int_value = va_arg(arg, int);
	number = ft_itoa(pointer->int_value);
	ft_print_d_i_u_xX(pointer, number);
	free(number);
}
