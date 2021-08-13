#include "printf.h"

int	ft_atoi(const char *str, t_list *pointer)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
		(pointer->index)++;
	}
	return (result);
}

t_list	*ft_create_elem(void)
{
	t_list	*pointer;

	pointer = malloc(sizeof(t_list));
	if (pointer == NULL)
		return (NULL);
	return (pointer);
}

void	ft_print_number(t_list *pointer, char *number)
{
	if (pointer->precision == 0 && pointer->precision_have \
	== 1 && pointer->int_value == 0)
		return ;
	while (*number)
	{
		write(1, number, 1);
		(pointer->length)++;
		number++;
	}
}

void	ft_print_string(t_list *pointer, char *number)
{
	if (pointer->count_symbol >= 0)
	{
		while (pointer->count_symbol)
		{
			write(1, number, 1);
			(pointer->length)++;
			number++;
			(pointer->count_symbol)--;
		}
	}
}

void	ft_print_symbol(t_list *pointer, char symbol)
{
	if (pointer->count_symbol >= 0)
	{
		while (pointer->count_symbol)
		{
			write(1, &symbol, 1);
			(pointer->length)++;
			(pointer->count_symbol)--;
		}
	}
}
