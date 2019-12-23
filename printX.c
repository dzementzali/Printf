#include "ft_printf.h"

//|========================Hexadecimal X================|
void myprintf_X(va_list *list_printf, t_prtf *structprtf)
{
	int nb;

	nb = va_arg(*list_printf, int);
	if (structprtf->minus == 1 && structprtf->zero == 1)
		return;
	if (structprtf->zero == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
		write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
	if (structprtf->minus == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
		write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
	if (structprtf->width != 0 && structprtf->precisionfound == 0 && structprtf->zero == 0)
	{
		if (structprtf->width <= ft_strlen(ft_itoa_base(nb, 16, 1)))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		else
		{
			if (structprtf->minus == 1)
			{
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
				print_recursiv(' ', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 1 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1)))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1)))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		}
	}
	if (structprtf->precisionfound == 0 && structprtf->width != 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->width <= ft_strlen(ft_itoa_base(nb, 16, 1)))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		else
		{
			print_recursiv('0', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		}
	}
	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1)))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 0)
	{
		if ((structprtf->width <= ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1))))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		if ((structprtf->width > ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1))))
		{
			if (structprtf->minus == 1)
			{
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
				print_recursiv(' ', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
			}
		}
		if ((structprtf->width <= ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision > ft_strlen(ft_itoa_base(nb, 16, 1))))
		{
			print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		}
		if ((structprtf->width > ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision > ft_strlen(ft_itoa_base(nb, 16, 1))))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
			}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
				{
					print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
					write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
					write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
				}
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 1)
	{
		if ((structprtf->width <= ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1))))
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		if ((structprtf->width > ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision <= ft_strlen(ft_itoa_base(nb, 16, 1))))
		{
			if (structprtf->minus == 1)
			{
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
				print_recursiv(' ', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_strlen(ft_itoa_base(nb, 16, 1))));
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
			}
		}
		if ((structprtf->width <= ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision > ft_strlen(ft_itoa_base(nb, 16, 1))))
		{
			print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
			write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		}
		if ((structprtf->width > ft_strlen(ft_itoa_base(nb, 16, 1))) && (structprtf->precision > ft_strlen(ft_itoa_base(nb, 16, 1))))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
				write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
			}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
				{
					print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
					write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - ft_strlen(ft_itoa_base(nb, 16, 1))));
					write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
				}
			}
		}
	}

	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0
			&& structprtf->width == 0 && structprtf->precisionfound == 0)
		write(1, ft_itoa_base(nb, 16, 1), ft_strlen(ft_itoa_base(nb, 16, 1)));
		
}




