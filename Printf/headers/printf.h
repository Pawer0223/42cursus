#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
// remove !!!!
#include <stdio.h>

typedef struct s_flag
{
	char plus;
	char minus;
	char space;
	char hash;
	char zero;
}				t_flag;
typedef struct s_input
{
	char	*str;
	char	sign;
	int		len;
}				t_input;
typedef struct	s_printf
{
	va_list	*ap;
	t_input	*input;
	t_flag	*flags;
	char	*length;
	char	specifier;
	int		width;
	int		precision_len;
}				t_printf;
t_printf 		*g_info;
int				g_i;
long long		g_w_cnt;
/* global funcs */
int				init_g(va_list *ap);
void			clear_g(void);
void			free_g(void);
/* check funcs */
int				check_format(const char	*format);
int				check_size(const char *format, int type);
/* set_input_filter */
int				ft_set_input_filter(char spec);
/* set input caller funcs */
int				ft_set_di(char	*length);
int				ft_set_ux(char	*length, char spec);
int				ft_set_s();
void			ft_set_n(char	*length);
int				ft_set_p();
int				ft_set_fge();
/* set input funcs */
int				set_di_input(long long n);
int				set_u_input(unsigned long long n);
int				set_x_input(unsigned long long n);
int				set_p_input(unsigned long long n);
int				set_str_input(char *input_str);
int             set_f_input(double n);
/* format write*/
void			ft_format_write(t_flag *flags);
//void			percent_write(t_flag *flags);
void			write_padding(char padding, int end);
void			ft_ascii_write(int n);
/* common */
void			fill_is_zero(t_input* input, int idx);
void			set_input_sign(t_input* input);
void			set_double_sign(t_input *input, char *ptr);
/* math*/
double			ft_pow(double base, double exponent);
void			ft_round(char* str, int idx, int pre, double n);
/* manage */
double			get_number(double d, int need_last);
int				get_left_size(double d);
/* remove !!! for Test .. */
void			all_print();
void			t_printf_print();
void			t_input_print();
int				ft_printf(const char *format, ...);
#endif
