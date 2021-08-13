#include "printf.h"

void	ft_print_u(t_list *pointer, va_list arg)
{
	char	*number;

	pointer->int_value = va_arg(arg, unsigned int);
	number = ft_itoa(pointer->int_value);
	ft_print_d_i_u_xX(pointer, number);
	free(number);
}

void	ft_print_x(t_list *pointer, va_list arg)
{
	char	*number;
	char	characters[7];

	ft_print_p_utility(characters, "abcdef");
	pointer->int_value = va_arg(arg, unsigned int);
	number = ft_itoa_to16(pointer->int_value, characters);
	ft_print_d_i_u_xX(pointer, number);
	free(number);
}

void	ft_print_X(t_list *pointer, va_list arg)
{
	char	*number;
	char	characters[7];

	ft_print_p_utility(characters, "ABCDEF");
	pointer->int_value = va_arg(arg, unsigned int);
	number = ft_itoa_to16(pointer->int_value, characters);
	ft_print_d_i_u_xX(pointer, number);
	free(number);
}

void	ft_print_d_i_u_xX(t_list *pointer, char *number)
{
	if (pointer->precision_have == 1 && pointer->precision >= 0)
		pointer->zero = 0;
	if (pointer->width >= ft_strlen(number) && \
	pointer->precision <= ft_strlen_digit(number))
		ft_have_only_width(pointer, number);
	else if (pointer->width <= ft_strlen(number) && \
	pointer->precision >= ft_strlen(number))
		ft_have_only_precision(pointer, number);
	else if (pointer->width > ft_strlen(number) && \
	pointer->precision >= ft_strlen(number))
		ft_have_width_and_precision(pointer, number);
	else
	{
		if (pointer->type == 'p')
			ft_print_0x(pointer);
		ft_print_number(pointer, number);
	}
}

void	ft_print_p_utility(char *characters, char *str)
{
	characters[0] = str[0];
	characters[1] = str[1];
	characters[2] = str[2];
	characters[3] = str[3];
	characters[4] = str[4];
	characters[5] = str[5];
	characters[6] = str[6];
}
