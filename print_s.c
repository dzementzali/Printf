#include "ft_printf.h"

//|========================String================|
void ft_normal_s(char *str, t_prtf *structprtf, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (structprtf->precisionfound && (structprtf->precision > ft_strlen(str) || structprtf->precision < 0))
		len = ft_strlen(str);
	else if (structprtf->precisionfound && !structprtf->precision && structprtf->width)
		len = 0;
	else if (structprtf->precisionfound)
		len = structprtf->precision;
	else
		len = structprtf->precision + ft_strlen(str);
	while (structprtf->width-- > len)
		ft_putprint(c, structprtf);
	while (str[i] && (structprtf->precision-- || !structprtf->precisionfound))
	{
		ft_putprint(str[i], structprtf);
		i++;
	}
}
void ft_minus_s(char *str, t_prtf *structprtf, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	structprtf->zero = 0;
	if (structprtf->precisionfound && (structprtf->precision > ft_strlen(str) || structprtf->precision < 0))
		len = ft_strlen(str);
	else if (structprtf->precisionfound && !structprtf->precision && structprtf->width)
		len = 0;
	else if (structprtf->precisionfound && structprtf->precision > 0)
		len = structprtf->precision;
	else
		len = structprtf->precision + ft_strlen(str);
	while (str[i] && (structprtf->precision-- || !structprtf->precisionfound))
	{
		ft_putprint(str[i], structprtf);
		i++;
	}
	while (structprtf->width-- > len)
		ft_putprint(c, structprtf);
}
void ft_nullstring(t_prtf *structprtf, char c)
{
	char *nul;
	int len;

	len = 6;
	if (structprtf->precisionfound && (structprtf->precision >= 0 && structprtf->precision < 6))
		len = structprtf->precision;
	nul = ft_substr("(null)", 0, len);
	if ((structprtf->precision < 0) && !structprtf->width)
		ft_putstr(nul, structprtf);
	else if (structprtf->minus)
		ft_minus_s(nul, structprtf, c);
	else
		ft_normal_s(nul, structprtf, c);
	free(nul);
}
void myprintf_s(va_list *list_printf, t_prtf *structprtf)
{
	char *str;
	char c;

	str = va_arg(*list_printf, char *);
	c = ' ';
	if (structprtf->zero && !structprtf->precisionfound && !structprtf->minus)
		c = '0';
	if (str == NULL)
		ft_nullstring(structprtf, c);
	if (str == NULL || (!*str && !structprtf->width))
		return;
	if (structprtf->precision < 0)
		structprtf->precision = ft_strlen(str);
	if (!*str)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
	}
	if (!*str)
		return;
	if (structprtf->minus)
		ft_minus_s(str, structprtf, c);
	else
		ft_normal_s(str, structprtf, c);
}
