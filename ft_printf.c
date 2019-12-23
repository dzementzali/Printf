#include "ft_printf.h"

int ft_printf(char *str, ...)
{
	int i;
	int ret;

	va_list list_printf;
	t_prtf structprtf;
	va_start(list_printf, str);

	structprtf.percent = 0;
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			init_struc(&structprtf);
			structprtf.percent = i;
			if (check_flag(str, &i) == 0)
			{
				printf("No flag");
				return (0);
			}
			else
			{
				structprtf.flag = str[i];
				check_mod(str, &structprtf, list_printf);
				//print_struct(structprtf);
				apply_mod(&structprtf, &list_printf);
			}
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			ret++;
		}
	}
	va_end(list_printf);
	return (ret + structprtf.len);
}
