#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char		type;
	long		width;
	int			minus;
	int			zero;
	long		precision;
	long		index;
	long		length;
	long		int_value;
	int			error;
	int			precision_have;
	long		count_symbol;
	int			have_space;
	int			free;
}				t_list;

int		ft_printf(const char *src, ...);
long	ft_first(char *src, va_list arg);
void	ft_parser(t_list *pointer, char *src, va_list arg);
void	ft_parse_flag(t_list *pointer, char *src, va_list arg);
void	ft_parse_other(t_list *pointer, char *src, va_list arg);
void	ft_parse_width(t_list *pointer, char *src, va_list arg);
void	ft_parse_precision(t_list *pointer, char *src, va_list arg);
void	ft_parse_type(t_list *pointer, char *src, va_list arg);
int		ft_isadigit(char c);
int		ft_isastar(char c);
void	ft_print_d_i_u_xX(t_list *pointer, char *number);
void	ft_print_d_i(t_list *pointer, va_list arg);
void	ft_print_u(t_list *pointer, va_list arg);
void	ft_print_x(t_list *pointer, va_list arg);
void	ft_print_X(t_list *pointer, va_list arg);
void	ft_print_s(t_list *pointer, va_list arg);
void	ft_print_c(t_list *pointer, va_list arg);
void	ft_print_p(t_list *pointer, va_list arg);
void	ft_print_characters(t_list *pointer, char *number);
int		ft_numlen(long n);
long	ft_short(char *s, long nn);
char	*ft_itoa(long n);
long	ft_strlen(const char *str);
t_list	*ft_create_elem(void);
int		ft_atoi(const char *str, t_list *pointer);
void	ft_have_only_width(t_list *pointer, char *number);
void	ft_print_symbol(t_list *pointer, char symbol);
void	ft_print_number(t_list *pointer, char *number);
void	ft_have_only_precision(t_list *pointer, char *number);
void	ft_have_width_and_precision(t_list *pointer, char *number);
char	*ft_itoa_to16_if0(char *result);
void	ft_itoa_to16_if_positive(char *result, \
long count, long long n, char *characters);
char	*ft_itoa_to16(long long n, char *characters);
void	ft_print_0x(t_list *pointer);
void	ft_update_str(t_list *pointer);
void	ft_print_string(t_list *pointer, char *number);
void	ft_completion(char *number);
void	ft_initialization(t_list *pointer);
void	ft_print_percent(t_list *pointer);
long	ft_strlen_digit(const char *str);
void	ft_print_characters_utility(t_list *pointer, char *number);
void	ft_have_only_width_utility(t_list *pointer, char *number);
void	ft_have_width_and_precision_utility(t_list *pointer, char *number);
void	ft_first_utility(char *src, t_list *pointer);
void	ft_print_p_utility(char *characters, char *str);

#endif
