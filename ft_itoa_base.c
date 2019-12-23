#include "ft_printf.h"

static int		conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

static int		conv_ex_maj(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

char	*ft_itoa_base(long long int value, int base, int maj)
{
	int					i;
	char				*str;
	long long int				tmp;
	
	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}	
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		if (maj == 1)
		str[i] = conv_ex_maj(tmp);
		else 
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}
