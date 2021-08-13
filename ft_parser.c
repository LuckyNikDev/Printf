#include "printf.h"

void	ft_parser(t_list *pointer, char *src, va_list arg)
{
	(pointer->index)++;
	if (src[pointer->index] == ' ')
	{
		pointer->have_space = 1;
		while (src[pointer->index] == ' ')
			(pointer->index)++;
	}
	ft_parse_flag(pointer, src, arg);
}

void	ft_parse_flag(t_list *pointer, char *src, va_list arg)
{
	pointer->zero = 0;
	pointer->minus = 0;
	while (1)
	{
		if (src[pointer->index] == '0' && src[pointer->index] != '\0')
		{
			pointer->zero = 1;
			(pointer->index)++;
		}
		else if (src[pointer->index] == '-' && src[pointer->index] != '\0')
		{
			pointer->minus = 1;
			(pointer->index)++;
		}
		else
			break ;
	}
	if (!(pointer->minus) && !(pointer->zero))
		pointer->zero = 0;
	if (src[pointer->index] != '\0')
		ft_parse_other(pointer, src, arg);
}

void	ft_parse_other(t_list *pointer, char *src, va_list arg)
{
	pointer->precision = 0;
	ft_parse_width(pointer, src, arg);
	if (src[pointer->index] == '.')
		ft_parse_precision(pointer, src, arg);
	ft_parse_type(pointer, src, arg);
	if (!(pointer->error))
		(pointer->index)++;
}

void	ft_parse_width(t_list *pointer, char *src, va_list arg)
{
	pointer->width = 0;
	if (ft_isadigit(src[pointer->index]) || ft_isastar(src[pointer->index]))
	{
		if (ft_isastar(src[pointer->index]))
		{
			pointer->width = va_arg(arg, int);
			(pointer->index)++;
		}
		else
			pointer->width = ft_atoi(&(src[pointer->index]), pointer);
	}
	if (pointer->width < 0)
	{
		pointer->width *= -1;
		pointer->minus = 1;
	}
}

void	ft_parse_precision(t_list *pointer, char *src, va_list arg)
{
	if (src[pointer->index] == '.')
		pointer->precision_have = 1;
	(pointer->index)++;
	if (ft_isastar(src[pointer->index]))
	{
		pointer->precision_have = 1;
		pointer->precision = va_arg(arg, int);
		(pointer->index)++;
	}
	else if (src[pointer->index] != '\0' && ft_isadigit(src[pointer->index]))
	{
		pointer->precision = ft_atoi(&(src[pointer->index]), pointer);
		pointer->precision_have = 1;
	}
}
