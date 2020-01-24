#include "ft_printf.h"
int ft_count(long nb)
{
	int count;

	count = 0;
	if (nb < 0)
		count++;
	if (nb == 0)
		count++;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

//|========================Digit && Integer================|

void ft_width_precision_di(long nb, t_prtf *structprtf, char wp, char c)
{
	int len;

	len = ft_count(nb);
	if (structprtf->precision > ft_count(nb) && structprtf->precisionfound)
		len = structprtf->precision;
	if (wp == 'w')
		while (structprtf->width-- > len)
			ft_putprint(c, structprtf);
	if (wp == 'p')
	{
		len = structprtf->precision;
		while (len-- - ft_count(nb) > 0)
			ft_putprint('0', structprtf);
	}
}
void ft_minus_di(long nb, t_prtf *structprtf, char c)
{
	structprtf->zero = 0;
	if (structprtf->precisionfound && !structprtf->precision && !nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return;
	}
	else
	{	
		if (structprtf->precisionfound)
			ft_width_precision_di(nb, structprtf, 'p', c);
		ft_putnbr(nb, structprtf);
		ft_width_precision_di(nb, structprtf, 'w', c);
	}
}
void ft_normal_di(long nb, t_prtf *structprtf, char c)
{
	if (structprtf->precisionfound && !structprtf->precision && !nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return;
	}
	else
	{
		ft_width_precision_di(nb, structprtf, 'w', c);
		if (structprtf->precisionfound)
			ft_width_precision_di(nb, structprtf, 'p', c);
		ft_putnbr(nb, structprtf);
	}
}
void myprintf_di(va_list *list_printf, t_prtf *structprtf)
{
	long nb;
	char c;

	nb = va_arg(*list_printf, int);
	if (structprtf->precisionfound && !structprtf->precision && !nb && !structprtf->width)
		return;
	c = ' ';
	if (structprtf->zero && !structprtf->minus && (!structprtf->precisionfound || structprtf->precision < 0))
		c = '0';
	if (nb < 0 && ((structprtf->zero && (!structprtf->precisionfound || structprtf->precision < 0)) ||
	(structprtf->precisionfound && structprtf->precision >= ft_count(nb) && structprtf->precision > 0)))
	{
		ft_putprint('-', structprtf);
		structprtf->width--;
		nb = nb * -1;
	}
	if (structprtf->minus)
		ft_minus_di(nb, structprtf, c);
	else
		ft_normal_di(nb, structprtf, c);
}
