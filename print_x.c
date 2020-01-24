#include "ft_printf.h"

//|========================Hexadecimal x================|
void	ft_width_precision_x(char *str, t_prtf *structprtf, char wp, char c)
{
	int		len;

	len = ft_strlen(str);
	if (structprtf->precision > ft_strlen(str) && structprtf->precisionfound)
		len = structprtf->precision;
	if (wp == 'w')
		while (structprtf->width-- > len)
			ft_putprint(c, structprtf);
	if (wp == 'p')
	{
		len = structprtf->precision;
		while (((len--) - (ft_strlen(str))) > 0)
			ft_putprint('0', structprtf);
	}
}
void ft_normal_x(char *str, t_prtf *structprtf, char c, int nb)
{
	int i;

	i = 0;
	if (structprtf->precisionfound && !structprtf->precision && !nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	else
	{
		ft_width_precision_x(str, structprtf, 'w', c);
		if (structprtf->precisionfound)
			ft_width_precision_x(str, structprtf, 'p', c);
		ft_putstr(str, structprtf);
	}
}

void ft_minus_x(char *str, t_prtf *structprtf, char c, int nb)
{
	int i;

	structprtf->zero = 0;
	c = ' ';
	i = 0;
	if (structprtf->precisionfound && !structprtf->precision && !nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return;
	}
	else
	{
		if (structprtf->precisionfound)
			ft_width_precision_x(str, structprtf, 'p', c);
		ft_putstr(str, structprtf);
		ft_width_precision_x(str, structprtf, 'w', c);
	}
}
void myprintf_x(va_list *list_printf, t_prtf *structprtf)
{
	unsigned int nb;
	char *str;
	char c;

	nb = va_arg(*list_printf, int);
	if (!nb && structprtf->precisionfound && !structprtf->precision && !structprtf->width)
		return;
	str = (structprtf->conv == 'X')? ft_itoa_base(nb, "0123456789ABCDEF") : ft_itoa_base(nb, "0123456789abcdef");
	c = ' ';
	if (structprtf->zero && !structprtf->minus && (!structprtf->precisionfound || structprtf->precision < 0))
		c = '0';
	if (structprtf->precision < 0)
		structprtf->precision = ft_strlen(str);
	if (!*str && !structprtf->width)
		return;
	if (structprtf->minus && structprtf->width)
		ft_minus_x(str, structprtf, c, nb);
	else
		ft_normal_x(str, structprtf, c, nb);
	free(str);
}
