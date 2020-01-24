#include "ft_printf.h"

//============================== Func initialisation structure ==============================

void init_struc(t_prtf *structure)
{
	structure->conv = 0;
	structure->star = 0;
	structure->zero = 0;
	structure->minus = 0;
	structure->width = 0;
	structure->precision = 0;
	structure->precisionfound = 0;
	structure->line = NULL;
}
//============================== Applications conv ==============================

void apply_conv(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->conv == 's')
		myprintf_s(list_printf, structprtf);

	else if (structprtf->conv == 'c')
		myprintf_c(list_printf, structprtf);

	else if (structprtf->conv == 'p')
		myprintf_p(list_printf, structprtf);

	if (structprtf->conv == 'd' || structprtf->conv == 'i')
		myprintf_di(list_printf, structprtf);

	if (structprtf->conv == 'u')
		myprintf_u(list_printf, structprtf);

	if (structprtf->conv == 'X' || structprtf->conv == 'x')
		myprintf_x(list_printf, structprtf);

	else if (structprtf->conv == '%')
		myprint_percent('%', structprtf);
}
//============================== Recuperation nombres ==============================

int recup_number(char *str, int *i, t_prtf *structprtf)
{
	int beg;

	while (str[*i] != structprtf->conv && ft_isdigit(str[*i]) != 1)
		*i = *i + 1;
	beg = *i;
	while (ft_isdigit(str[*i]))
		*i = *i + 1;

	*i = *i - 1;
	return (ft_atoi(str + beg));
}
//============================== Remplis struct ==============================

void check_flag(char *str, t_prtf *structprtf, va_list list_printf)
{
	int i;

	i = structprtf->percent;
	while (str[i] != structprtf->conv)
	{
		while (str[i] == '-')
		{
			structprtf->minus = 1;
			i++;
		}
		while (str[i] == '0')
		{
			structprtf->zero = 1;
			i++;
		}
		if (str[i] == '*' && structprtf->precisionfound == 0)
		{
			structprtf->star = 1;
			structprtf->width = (va_arg(list_printf, int));
			if (structprtf->width < 0)
			{
				structprtf->minus = 1;
				structprtf->width = structprtf->width * -1;
			}
			else
			structprtf->width = structprtf->width;
				 i++;
		}
		if (ft_isdigit(str[i]) == 1 && str[i] != '0' && structprtf->precisionfound == 0)
		{
			structprtf->width = recup_number(str, &i, structprtf);
			i++;
		}
		if (str[i] == '.')
		{
			structprtf->precisionfound = 1;
			if (str[i + 1] == '*')
			{
				structprtf->star = 1;
				structprtf->precision = va_arg(list_printf, int);
				i = i + 2;
			}
			if (ft_isdigit(str[i + 1]) == 1 && str[i] != structprtf->conv)
			{
				structprtf->precision = recup_number(str, &i, structprtf);
				i++;
			}
			else
				return;
		}
		else
			return;
	}
}
//============================== Verif presence "idsuxXetc.." ==============================

int check_conv(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == 's' || str[*i] == 'd' || str[*i] == 'c' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'i' || str[*i] == '%' || str[*i] == 'p')
			return (1);
		*i = *i + 1;
	}
	return (0);
}
//============================== Incrementation len ==============================
void incr_len(t_prtf *structprtf, int nb)
{
	while (nb > 0)
	{
		structprtf->len++;
		nb--;
	}
}

//============================Putchar===========================================

void	ft_putprint(char c, t_prtf *structprtf)
{
	write(1, &c, 1);
	structprtf->len++;	
}
