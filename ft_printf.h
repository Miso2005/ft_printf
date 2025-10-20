
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_hex_upper(unsigned long x, int *count);
void	ft_hex_low(unsigned long x, int *count);
int		ft_putp(void *p, int *count);
int		is(char c);
int		ft_printf(const char *s, ...);

#endif
