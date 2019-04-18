#include "libargc.h"

static int		ft_isspace(int c)
{
	if ((unsigned char)c == ' ')
		return (1);
	if ((unsigned char)c == '\f')
		return (1);
	if ((unsigned char)c == '\n')
		return (1);
	if ((unsigned char)c == '\r')
		return (1);
	if ((unsigned char)c == '\t')
		return (1);
	if ((unsigned char)c == '\v')
		return (1);
	return (0);
}

static int		ft_isdigit(int c)
{
	if ((unsigned char)c < '0' || (unsigned char)c > '9')
		return (0);
	return (1);
}

int				ft_atoi(char const *s)
{
	int		sign;
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = s[i] == '-' ? -1 : 1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		nb = nb * 10 + s[i] - 48;
		i++;
	}
	return ((int)(nb * sign));
}
