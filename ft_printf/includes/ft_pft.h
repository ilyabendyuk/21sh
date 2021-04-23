#ifndef FT_PFT_H
# define FT_PFT_H
# define BUFF_SIZE 2048

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <inttypes.h>
# include <stdint.h>
# include <ctype.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_flags
{
	int			minus;
	int			plus;
	int			precision;
	int			zero;
	int			grid;
	int			space;
	int			width;
	char		spec[4];
	int			asterisk;
	int			no_prec;
	int			zero_num;
	char		*buf;
	int			buffer;
	int			count;
	int			fd;
}				t_flags;

void			init_struct(t_flags *flags, int fd);
int				ft_atoi_pft(const char *str);
void			print_addr(intptr_t a, t_flags *flags);
void			ft_putchar(const char ch, t_flags *pft);
int				ft_strcmp_pft(const char *src1, const char *src2);
void			ft_putstr(const char *str, t_flags *flags);
void			clear_buf(t_flags *flags);
void			ft_ox(intmax_t n, t_flags *pft, int l, int h);
int				get_pres(t_flags *pft, int len, int grid, char conv);
uintmax_t		get_overflow(long long n, int l, int h);
intmax_t		get_overflow_d(long long n, int l, int h);
void			ft_d(intmax_t n, t_flags *pft, int l, int h);
void			putnbr_overflow(long long n, t_flags *pft);
void			ft_print_d(t_flags *pft, char *print, int len, int min);
int				get_pres_d(t_flags *pft, int len, int min);
int				get_pres_u(t_flags *pft, int len);
void			ft_u(intmax_t n, t_flags *pft, int l, int h);
char			*processing_flags(char *format, va_list ptr, t_flags *pft);
int				ft_int_len(int num);
void			ft_putstr_len(const char *str, t_flags *pft, int prec1);
int				ft_strlen(const char *str);
char			*processing_flags(char *format, va_list ptr, t_flags *pft);
void			print_uint(unsigned int num, t_flags *pft);
void			print_char(va_list ptr, t_flags *pft);
void			print_int(int num, t_flags *pft);
void			print_str(va_list ptr, t_flags *pft);
void			print_space_char(int len, char ch, t_flags *flags);
char			*get_spec(char *format, t_flags *flags);
void			get_4flags(char *format, t_flags *flags, va_list ptr);
char			*get_space(char *format, t_flags *flags);
char			*get_precision(char *format, t_flags *flags);
void			ft_print_precision(int len, char c, t_flags *flags);
void			ft_printstr_len1(char *str, int len, t_flags *flags);
char			get_base(int nb, char flag);
int				get_plus(t_flags *pft, int len1, int len, int grid);
int				get_minus(t_flags *pft, int len1, int len, int grid);
void			ft_print_ox(t_flags *pft, char *print, char conv, int len);
void			itoa_base_put(uintmax_t nb, t_flags *pft, char conv, int len);
void			ft_r(const char *str, t_flags *flags);
void			ft_b(intmax_t nb, t_flags *flags);

#endif
