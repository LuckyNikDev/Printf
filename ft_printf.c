#include "printf.h"

int	ft_printf(const char *src, ...)
{
	long	length;
	va_list	arg;

	va_start(arg, src);
	length = ft_first((char *)src, arg);
	va_end(arg);
	return (length);
}

long 	ft_first(char *src, va_list arg)
{
	t_list	*pointer;
	long	length;

	pointer = ft_create_elem();
	if (!pointer)
		return (-1);
	ft_initialization(pointer);
	while (src[pointer->index])
	{
		if (src[pointer->index] == '%')
		{
			ft_parser(pointer, src, arg);
			if (pointer->error)
				break ;
			ft_update_str(pointer);
		}
		else
			ft_first_utility(src, pointer);
	}
	length = pointer->length;
	free(pointer);
	return (length);
}

void 	ft_first_utility(char *src, t_list *pointer)
{
	write (1, &src[pointer->index], 1);
	(pointer->index)++;
	(pointer->length)++;
}

void	ft_initialization(t_list *pointer)
{
	pointer->type = '0';
	pointer->width = 0;
	pointer->minus = 0;
	pointer->zero = 0;
	pointer->precision = 0;
	pointer->index = 0;
	pointer->length = 0;
	pointer->int_value = 0;
	pointer->error = 0;
	pointer->precision_have = 0;
	pointer->count_symbol = 0;
	pointer->have_space = 0;
	pointer->free = 0;
}

void	ft_parse_type(t_list *pointer, char *src, va_list arg)
{
	if (src[pointer->index] == 's')
		ft_print_s(pointer, arg);
	else if (src[pointer->index] == 'c')
		ft_print_c(pointer, arg);
	else if (src[pointer->index] == 'p')
		ft_print_p(pointer, arg);
	else if (src[pointer->index] == 'd')
		ft_print_d_i(pointer, arg);
	else if (src[pointer->index] == 'i')
		ft_print_d_i(pointer, arg);
	else if (src[pointer->index] == 'u')
		ft_print_u(pointer, arg);
	else if (src[pointer->index] == 'x')
		ft_print_x(pointer, arg);
	else if (src[pointer->index] == 'X')
		ft_print_X(pointer, arg);
	else if (src[pointer->index] == '%')
		ft_print_percent(pointer);
	else
		pointer->error = 1;
}
