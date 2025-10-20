
#include "ft_printf.h"

void	ft_hex_low(unsigned long x, int *count)
{
	char	s[16];
	int		i;

	i = 0;
	if (x == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	while (x > 0)
	{
		if (x % 16 > 9)
		{
			s[i++] = 'a' + (x % 16 - 10);
		}
		else
			s[i++] = '0' + x % 16;
		x /= 16;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(s[i--], count);
	}
}

int	ft_putp(void *p, int *count)
{
	unsigned long	n;
	int				i;

	n = (unsigned long)p;
	i = 0;
	if (!p)
	{
		ft_putstr("(nil)", count);
		return (5);
	}
	ft_putstr("0x", count);
	ft_hex_low(n, count);
	return (0);
}

int	is(char c)
{
	char	*s;
	int		i;

	i = 0;
	s = "cspdiuxX%";
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	handle_format(const char *s, int i, va_list args, int *count)
{
	if (!s)
		return (-1);
	if (s[i] == 'c')
		ft_putchar((char)va_arg(args, int), count);
	else if (s[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (s[i] == 'p')
		ft_putp(va_arg(args, void *), count);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (s[i] == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (s[i] == 'x')
		ft_hex_low(va_arg(args, unsigned int), count);
	else if (s[i] == 'X')
		ft_hex_upper(va_arg(args, unsigned int), count);
	else if (s[i] == '%')
		ft_putchar('%', count);
	else
	{
		ft_putchar('%', count);
		ft_putchar(s[i], count);
	}
	return (i + 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i = handle_format(s, i + 1, args, &count);
		}
		else
		{
			ft_putchar(s[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
