#include "printf.h"

void	ft_print_characters(t_list *pointer, char *number)
{
	if (pointer->width > ft_strlen(number) && \
	(!(pointer->precision_have) || pointer->precision >= ft_strlen(number)))
		ft_have_only_width(pointer, number);
	else if (pointer->precision < ft_strlen(number) && pointer->precision_have &&\
	pointer->width < ft_strlen(number) && pointer->width <= pointer->precision)
	{
		pointer->count_symbol = pointer->precision;
		ft_print_string(pointer, number);
	}
	else if (pointer->width > pointer->precision &&\
	pointer->precision < ft_strlen(number) && pointer->precision_have)
		ft_print_characters_utility(pointer, number);
	else
		ft_print_number(pointer, number);
}

void	ft_print_characters_utility(t_list *pointer, char *number)
{
	if (pointer->minus)
	{
		pointer->count_symbol = pointer->precision;
		ft_print_string(pointer, number);
		pointer->count_symbol = pointer->width - pointer->precision;
		ft_print_symbol(pointer, ' ');
	}
	else
	{
		pointer->count_symbol = pointer->width - pointer->precision;
		ft_print_symbol(pointer, ' ');
		if (pointer->precision)
			pointer->count_symbol = pointer->precision;
		ft_print_string(pointer, number);
	}
}

void	ft_have_only_precision(t_list *pointer, char *number)
{
	if (pointer->type == 'p')
		ft_print_0x(pointer);
	if (pointer->int_value < 0)
	{
		write(1, "-", 1);
		(pointer->length)++;
		number = &number[1];
	}
	pointer->count_symbol = pointer->precision - ft_strlen(number);
	ft_print_symbol(pointer, '0');
	ft_print_number(pointer, number);
}

void	ft_have_only_width(t_list *pointer, char *number)
{
	if (pointer->type == 'p')
		pointer->width -= 2;
	pointer->count_symbol = pointer->width - ft_strlen(number);
	if (pointer->precision == 0 && pointer->precision_have == 1 && \
	pointer->int_value == 0)
		pointer->count_symbol += ft_strlen(number);
	if (*number == '\0' && pointer->type != 's')
	{
		(pointer->count_symbol)--;
		(pointer->length)++;
	}
	if (pointer->minus || pointer->zero)
		ft_have_only_width_utility(pointer, number);
	else
	{
		ft_print_symbol(pointer, ' ');
		if (pointer->type == 'p')
			ft_print_0x(pointer);
		ft_print_number(pointer, number);
	}
}

void	ft_have_only_width_utility(t_list *pointer, char *number)
{
	if (pointer->minus)
	{
		if (pointer->type == 'p')
			ft_print_0x(pointer);
		ft_print_number(pointer, number);
		ft_print_symbol(pointer, ' ');
		return ;
	}
	if (pointer->int_value < 0)
	{
		write(1, "-", 1);
		(pointer->length)++;
		number = &number[1];
	}
	ft_print_symbol(pointer, '0');
	if (pointer->type == 'p')
		ft_print_0x(pointer);
	ft_print_number(pointer, number);
}
