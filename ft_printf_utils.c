#include "ft_printf.h"

//============================== Func initialisation structure ==============================

void init_struc(t_prtf *structure)
{
	structure->flag = 0;
	structure->star = 0;
	structure->zero = 0;
	structure->minus = 0;
	structure->width = 0;
	structure->precision = 0;
	structure->precisionfound = 0;
	structure->len = 0;
	structure->line = NULL;
}
//============================== Applications modificateurs ==============================

void apply_mod(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 'c' || structprtf->flag == 's' || structprtf->flag == 'p')
	{
		apply_scp(structprtf, list_printf);
	}
	if (structprtf->flag == 'd' || structprtf->flag == 'i' || structprtf->flag == 'u')
	{
		apply_diu(structprtf, list_printf);
	}
	if (structprtf->flag == 'x' || structprtf->flag == 'X')
	{
		apply_xX(structprtf, list_printf);
	}
	if (structprtf->flag == '%')
	{
		apply_percent(structprtf);
	}
}

void apply_scp(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 's')
		myprintf_s(list_printf, structprtf);

	if (structprtf->flag == 'c')
		myprintf_c(list_printf, structprtf);

	if (structprtf->flag == 'p')
		myprintf_p(list_printf, structprtf);
}

void apply_diu(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 'd' || structprtf->flag == 'i')
		myprintf_di(list_printf, structprtf);
	if (structprtf->flag == 'u')
		myprintf_u(list_printf, structprtf);
}

void apply_xX(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 'x')
		myprintf_x(list_printf, structprtf);
	if (structprtf->flag == 'X')
		myprintf_X(list_printf, structprtf);
}

//============================== Recuperation nombres ==============================

int recup_number(char *str, int *i, t_prtf *structprtf)
{
	int beg;

	while (str[*i] != structprtf->flag && ft_isdigit(str[*i]) != 1)
		*i = *i + 1;
	beg = *i;
	while (ft_isdigit(str[*i]))
		*i = *i + 1;

	*i = *i - 1;
	return (ft_atoi(str + beg));
}
//============================== Remplis struct ==============================

void check_mod(char *str, t_prtf *structprtf, va_list list_printf)
{
	int i;

	i = structprtf->percent;
	while (str[i] != structprtf->flag)
	{
		if (str[i] == '-' && structprtf->precision == 0)
		{
			structprtf->minus = 1;
			i++;
		}
		if (str[i] == '0')
		{
			structprtf->zero = 1;
			i++;
		}
		if (str[i] == '*' && structprtf->precisionfound == 0)
		{
			structprtf->star = 1;
			structprtf->width = va_arg(list_printf, int);
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
			if (ft_isdigit(str[i + 1]) == 1)
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

int check_flag(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == 's' || str[*i] == 'd' || str[*i] == 'c' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'i' || str[*i] == '%' || str[*i] == 'p')
			return (1);
		*i = *i + 1;
	}
	return (0);
}
