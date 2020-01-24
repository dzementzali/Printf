#include "ft_printf.h"

int ft_printf(char *str, ...)
{
	int i;
	va_list list_printf;
	t_prtf structprtf;
	va_start(list_printf, str);

	structprtf.percent = 0;
	structprtf.len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			init_struc(&structprtf);
			structprtf.percent = i;
			if (check_conv(str, &i) == 0)
			{
				printf("No flag");
				return(0);
			}
			else
			{
				structprtf.conv = str[i];
				check_flag(str, &structprtf, list_printf);
				apply_conv(&structprtf, &list_printf);
			}
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			structprtf.len++;
			i++;
		}
	}
	va_end(list_printf);
	//print_struct(structprtf);
	return (structprtf.len);
}
