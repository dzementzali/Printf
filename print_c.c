#include "ft_printf.h"

//|========================Char================|

void	ft_width_precision_c(t_prtf *structprtf, char wp, char space)
{
	if (wp == 'w')
	{
		while(structprtf->width > (structprtf->precision + 1))
		{
			ft_putprint(space, structprtf);
			structprtf->width--;
		}
	}
	if (wp == 'p')
	{
		while((structprtf->precision - 1) > 0)
		{
			ft_putprint('0', structprtf);
			structprtf->precision--;
		}
	}

}
void	ft_minus_c(t_prtf *structprtf, char c, char space)
{
	structprtf->zero = 0;
	if(structprtf->precisionfound && !structprtf->precision && !c && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(space ,structprtf);
		return;
	}
	if (structprtf->precisionfound)
		ft_width_precision_c(structprtf, 'p', space);
	ft_putprint(c, structprtf);
	if(structprtf->width > structprtf->precision)
		ft_width_precision_c(structprtf, 'w', space);


}
void	ft_normal_c(t_prtf *structprtf, char c, char space)
{
	if(structprtf->precisionfound && !structprtf->precision && !c && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(space, structprtf);
		return;
	}
	if (structprtf->width > structprtf->precision)
		ft_width_precision_c(structprtf, 'w', space);
	if(structprtf->precisionfound)
		ft_width_precision_c(structprtf, 'p', space);
	ft_putprint(c, structprtf);

}

void myprintf_c(va_list *list_printf, t_prtf *structprtf)
{
	char c;
	char space;

	c = va_arg(*list_printf, int);
	if (structprtf->precisionfound && !structprtf->precision && !c && !structprtf->width)
		return;
	if (structprtf->zero && !structprtf->precision && !structprtf->minus)
		space = '0';
	else
		space = ' ';
	if (structprtf->minus)
		ft_minus_c(structprtf, c, space);
	else 
		ft_normal_c(structprtf, c, space);
}
