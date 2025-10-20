#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	char	s[10];
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n *= -1;
	}
	while (n > 9)
	{
		s[i++] = n % 10 + 48;
		n /= 10;
	}
	s[i] = n % 10 + 48;
	while (i >= 0)
	{
		ft_putchar(s[i], count);
		i--;
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	char	s[10];
	int		i;

	i = 0;
	while (n > 9)
	{
		s[i++] = n % 10 + 48;
		n /= 10;
	}
	s[i] = n % 10 + 48;
	while (i >= 0)
	{
		ft_putchar(s[i], count);
		i--;
	}
}

void	ft_hex_upper(unsigned long x, int *count)
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
			s[i++] = 'A' + (x % 16 - 10);
		}
		else
			s[i++] = '0' + x % 16;
		x /= 16;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(s[i], count);
		i--;
	}
}
