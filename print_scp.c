#include "ft_printf.h"

//|========================String================|
void myprintf_s(va_list *list_printf, t_prtf *structprtf)
{
	char *str;

	str = va_arg(*list_printf, char *);
	if (structprtf->minus == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
	{
		write(1, str, ft_strlen(str));
	}
	if (structprtf->width != 0 && structprtf->precisionfound == 0)
	{
		if (ft_strlen(str) >= structprtf->width)
		{
			write(1, str, ft_strlen(str));
		}
		if (ft_strlen(str) < structprtf->width)
		{
			if (structprtf->minus == 0)
			{
				print_recursiv(' ', ((structprtf->width) - ft_strlen(str)));
				write(1, str, ft_strlen(str));
			}
			if (structprtf->minus == 1)
			{
				write(1, str, ft_strlen(str));
				print_recursiv(' ', ((structprtf->width) - ft_strlen(str)));
			}
		}
	}
	if (structprtf->precisionfound == 1 && structprtf->width == 0)
	{
		if (ft_strlen(str) <= structprtf->precision)
		{
			write(1, str, ft_strlen(str));
		}
		if (ft_strlen(str) > structprtf->precision)
		{
			write(1, str, structprtf->precision);
		}
	}
	if (structprtf->precisionfound == 1 && structprtf->width != 0)
	{
		if (ft_strlen(str) >= structprtf->width && ft_strlen(str) < structprtf->precision)
			write(1, str, ft_strlen(str));
		if (ft_strlen(str) < structprtf->width && ft_strlen(str) >= structprtf->precision)
		{
			if (structprtf->minus == 1)
			{
				write(1, str, structprtf->precision);
				print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				write(1, str, structprtf->precision);
			}
		}
		if (ft_strlen(str) < structprtf->width && ft_strlen(str) < structprtf->precision)
		{
			if (structprtf->minus == 1)
			{
				write(1, str, ft_strlen(str));
				print_recursiv(' ', ((structprtf->width) - ft_strlen(str)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - ft_strlen(str)));
				write(1, str, ft_strlen(str));
			}
		}
		if (ft_strlen(str) >= structprtf->width && ft_strlen(str) >= structprtf->precision)
		{
			write(1, str, structprtf->precision);
		}
	}
	if (structprtf->zero == 1)
		return;
	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0 && structprtf->width == 0 && structprtf->precisionfound == 0)
		write(1, str, ft_strlen(str));
}

//|========================Char================|
void myprintf_c(va_list *list_printf, t_prtf *structprtf)
{
	char c;

	c = va_arg(*list_printf, int);
	if (structprtf->zero == 1)
		return;
	if (structprtf->precisionfound == 1)
		return;
	if (structprtf->width != 0)
	{
		if (structprtf->minus == 0)
		{
			print_recursiv(' ', ((structprtf->width) - 1));
			write(1, &c, 1);
		}
		if (structprtf->minus == 1)
		{
			write(1, &c, 1);
			print_recursiv(' ', ((structprtf->width) - 1));
		}
	}
	if (structprtf->minus == 1 && structprtf->precisionfound == 0 && structprtf->width == 0)
		write(1, &c, 1);
	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0 && structprtf->width == 0 && structprtf->precisionfound == 0)
		write(1, &c, 1);
}

//|========================Pointeur================|
void myprintf_p(va_list *list_printf, t_prtf *structprtf)
{
	char *address;

	address = ft_strdup(ft_itoa_base(va_arg(*list_printf, unsigned long long int), 16, 0));

	if (structprtf->minus == 1 && structprtf->zero == 1)
		return;
	if (structprtf->zero == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
	{
		write(1, "0x", 2);
		write(1, address, ft_strlen(address));
	}
	if (structprtf->minus == 1 && structprtf->width == 0 && structprtf->precisionfound == 0)
	{
		write(1, "0x", 2);
		write(1, address, ft_strlen(address));
	}
	if (structprtf->width != 0 && structprtf->precisionfound == 0 && structprtf->zero == 0)
	{
		if (structprtf->width <= ft_strlen(address))
		{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		else
		{
			if (structprtf->minus == 1)
			{
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
				print_recursiv(' ', ((structprtf->width) - (ft_strlen(address) + 2)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - (ft_strlen(address) + 2)));
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 1 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_strlen(address))
		{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		else
		{
			print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
}

	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->precision <= ft_strlen(address))
		{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		else
		{
			print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
}
	if (structprtf->precisionfound == 0 && structprtf->width != 0 && structprtf->minus == 0 && structprtf->zero == 1)
	{
		if (structprtf->width <= ft_strlen(address))
		{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
	}
		else
		{
			print_recursiv('0', ((structprtf->width) - (ft_strlen(address) + 2)));
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
}
	if (structprtf->precisionfound == 1 && structprtf->width == 0 && structprtf->minus == 0 && structprtf->zero == 0)
	{
		if (structprtf->precision <= ft_strlen(address))
		{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
	}
		else
		{
			print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 0)
	{
		if ((structprtf->width <= ft_strlen(address)) && (structprtf->precision <= ft_strlen(address)))
		{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		if ((structprtf->width > ft_strlen(address)) && (structprtf->precision <= ft_strlen(address)))
		{
			if (structprtf->minus == 1)
			{
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
				print_recursiv(' ', ((structprtf->width) - (ft_strlen(address) + 2)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - (ft_strlen(address) + 2)));
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
			}
		}
		if ((structprtf->width <= ft_strlen(address)) && (structprtf->precision > ft_strlen(address)))
		{
			print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		if ((structprtf->width > ft_strlen(address)) && (structprtf->precision > ft_strlen(address)))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
		}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
			{
					print_recursiv('0', ((structprtf->precision) - ft_strlen(address)));
					write(1, "0x", 2);
					write(1, address, ft_strlen(address));
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
					write(1, "0x", 2);
					write(1, address, ft_strlen(address));
			}
			}
		}
	}

	if (structprtf->precisionfound == 1 && structprtf->width != 0 && structprtf->zero == 1)
	{
		if ((structprtf->width <= ft_strlen(address)) && (structprtf->precision <= ft_strlen(address)))
	{
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		if ((structprtf->width > ft_strlen(address)) && (structprtf->precision <= ft_strlen(address)))
		{
			if (structprtf->minus == 1)
			{
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
				print_recursiv(' ', ((structprtf->width) - (ft_strlen(address) + 2)));
			}
			else
			{
				print_recursiv(' ', ((structprtf->width) - (ft_strlen(address) + 2)));
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
			}
		}
		if ((structprtf->width <= ft_strlen(address)) && (structprtf->precision > ft_strlen(address)))
		{
			print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
			write(1, "0x", 2);
			write(1, address, ft_strlen(address));
		}
		if ((structprtf->width > ft_strlen(address)) && (structprtf->precision > ft_strlen(address)))
		{
			if (structprtf->width <= structprtf->precision)
			{
				print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
				write(1, "0x", 2);
				write(1, address, ft_strlen(address));
		}
			if (structprtf->width > structprtf->precision)
			{
				if (structprtf->minus == 1)
			{
					print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
					write(1, "0x", 2);
					write(1, address, ft_strlen(address));
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
				}
				else
				{
					print_recursiv(' ', ((structprtf->width) - (structprtf->precision)));
					print_recursiv('0', ((structprtf->precision) - (ft_strlen(address) + 2)));
					write(1, "0x", 2);
					write(1, address, ft_strlen(address));
			}
			}
		}
	}

	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0 && structprtf->width == 0 && structprtf->precisionfound == 0)
	{
		write(1, "0x", 2);
		write(1, address, ft_strlen(address));
	}
}
