#include "ft_printf.h"
int ft_count(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int ft_count_unsigned(unsigned int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

//|========================Digit && Integer================|
void myprintf_di(va_list *list_printf, t_prtf *structprtf)
{
	int nb;

	nb = va_arg(*list_printf, int);
	if (structprtf->minus == 1 && structprtf->zero == 1)
		return;
	if (structprtf->zero == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
		ft_putnbr(nb);
	if (structprtf->minus == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
		ft_putnbr(nb);
	if (structprtf->width != 0 && structprtf->precisionfound == 0 && structprtf->zero == 0)
	{
		if (structprtf->width <= ft_count(nb))
			ft_putnbr(nb);
		else
		{
			if (structprtf->minus == 1)
			{
				ft_putnbr(nb);
				print_recursiv(' ', ((structprtf->width) - ft_count(nb)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_count(nb)));
				ft_putnbr(nb);
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 1 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_count(nb))
			ft_putnbr(nb);
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
			ft_putnbr(nb);
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->precision <= ft_count(nb))
			ft_putnbr(nb);
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
			ft_putnbr(nb);
		}
	}
	if (structprtf->precisionfound == 0 && structprtf->width != 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->width <= ft_count(nb))
			ft_putnbr(nb);
		else
		{
			print_recursiv('0', ((structprtf->width) - ft_count(nb)));
			ft_putnbr(nb);
		}
	}
	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_count(nb))
			ft_putnbr(nb);
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
			ft_putnbr(nb);
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 0)
	{
		if ((structprtf->width <= ft_count(nb)) && (structprtf->precision <= ft_count(nb)))
			ft_putnbr(nb);
		if ((structprtf->width > ft_count(nb)) && (structprtf->precision <= ft_count(nb)))
		{
			if (structprtf->minus == 1)
			{
				ft_putnbr(nb);
				print_recursiv(' ', ((structprtf->width) - ft_count(nb)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_count(nb)));
				ft_putnbr(nb);
			}
		}
		if ((structprtf->width <= ft_count(nb)) && (structprtf->precision > ft_count(nb)))
		{
			print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
			ft_putnbr(nb);
		}
		if ((structprtf->width > ft_count(nb)) && (structprtf->precision > ft_count(nb)))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
				ft_putnbr(nb);
			}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
				{
					print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
					ft_putnbr(nb);
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
					ft_putnbr(nb);
				}
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 1)
	{
		if ((structprtf->width <= ft_count(nb)) && (structprtf->precision <= ft_count(nb)))
			ft_putnbr(nb);
		if ((structprtf->width > ft_count(nb)) && (structprtf->precision <= ft_count(nb)))
		{
			if (structprtf->minus == 1)
			{
				return;
			}
			else
			{
				print_recursiv('0', ((structprtf->width) - ft_count(nb)));
				ft_putnbr(nb);
			}
		}
		if ((structprtf->width <= ft_count(nb)) && (structprtf->precision > ft_count(nb)))
		{
			print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
			ft_putnbr(nb);
		}
		if ((structprtf->width > ft_count(nb)) && (structprtf->precision > ft_count(nb)))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
				ft_putnbr(nb);
			}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
				{
					return;
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - ft_count(nb)));
					ft_putnbr(nb);
				}
			}
		}
	}

	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0 && structprtf->width == 0 && structprtf->precisionfound == 0)
		ft_putnbr(nb);
}

//|========================Unsigned integer================|
void myprintf_u(va_list *list_printf, t_prtf *structprtf)
{
	int nb;

	nb = va_arg(*list_printf, int);
	if (structprtf->minus == 1 && structprtf->zero == 1)
		return;
	if (structprtf->zero == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
		ft_putnbr_unsigned(nb);
	if (structprtf->minus == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
		ft_putnbr_unsigned(nb);
	if (structprtf->width != 0 && structprtf->precisionfound == 0 && structprtf->zero == 0)
	{
		if (structprtf->width <= ft_count_unsigned(nb))
			ft_putnbr_unsigned(nb);
		else
		{
			if (structprtf->minus == 1)
			{
				ft_putnbr_unsigned(nb);
				print_recursiv(' ', ((structprtf->width) - ft_count_unsigned(nb)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_count_unsigned(nb)));
				ft_putnbr_unsigned(nb);
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 1 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_count_unsigned(nb))
			ft_putnbr_unsigned(nb);
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
			ft_putnbr_unsigned(nb);
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->precision <= ft_count_unsigned(nb))
			ft_putnbr_unsigned(nb);
		else
		{
			print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
			ft_putnbr_unsigned(nb);
		}
	}
	if (structprtf->precisionfound == 0 && structprtf->width != 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->width <= ft_count_unsigned(nb))
			ft_putnbr_unsigned(nb);
		else
		{
			print_recursiv('0', ((structprtf->width) - ft_count_unsigned(nb)));
			ft_putnbr_unsigned(nb);
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 0)
	{
		if ((structprtf->width <= ft_count_unsigned(nb)) && (structprtf->precision <= ft_count_unsigned(nb)))
			ft_putnbr_unsigned(nb);
		if ((structprtf->width > ft_count_unsigned(nb)) && (structprtf->precision <= ft_count_unsigned(nb)))
		{
			if (structprtf->minus == 1)
			{
				ft_putnbr_unsigned(nb);
				print_recursiv(' ', ((structprtf->width) - ft_count_unsigned(nb)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_count_unsigned(nb)));
				ft_putnbr_unsigned(nb);
			}
		}
		if ((structprtf->width <= ft_count_unsigned(nb)) && (structprtf->precision > ft_count_unsigned(nb)))
		{
			print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
			ft_putnbr_unsigned(nb);
		}
		if ((structprtf->width > ft_count_unsigned(nb)) && (structprtf->precision > ft_count_unsigned(nb)))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
				ft_putnbr_unsigned(nb);
			}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
				{
					print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
					ft_putnbr_unsigned(nb);
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
					ft_putnbr_unsigned(nb);
				}
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 1)
	{
		if ((structprtf->width <= ft_count_unsigned(nb)) && (structprtf->precision <= ft_count_unsigned(nb)))
			ft_putnbr_unsigned(nb);
		if ((structprtf->width > ft_count_unsigned(nb)) && (structprtf->precision <= ft_count_unsigned(nb)))
		{
			if (structprtf->minus == 1)
			{
				return;
			}
			else
			{
				print_recursiv('0', ((structprtf->width) - ft_count_unsigned(nb)));
				ft_putnbr_unsigned(nb);
			}
		}
		if ((structprtf->width <= ft_count_unsigned(nb)) && (structprtf->precision > ft_count_unsigned(nb)))
		{
			print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
			ft_putnbr_unsigned(nb);
		}
		if ((structprtf->width > ft_count_unsigned(nb)) && (structprtf->precision > ft_count_unsigned(nb)))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
				ft_putnbr_unsigned(nb);
			}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
				{
					return;
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - ft_count_unsigned(nb)));
					ft_putnbr_unsigned(nb);
				}
			}
		}
	}

	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0 && structprtf->width == 0 && structprtf->precisionfound == 0)
		ft_putnbr_unsigned(nb);
}
