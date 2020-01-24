#include "ft_printf.h"

void	ft_putstr(char *str, t_prtf *structprtf)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putprint(str[i], structprtf);
		i++;
	}
}
