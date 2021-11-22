#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	nb_length(long long n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	if (n >= 0 && n < 10)
		length++;
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				i;
	long long		nb;

	nb = (long long)n;
	size = nb_length(nb);
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
	}
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar_fd(nb + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}