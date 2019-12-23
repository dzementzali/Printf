#include "ft_printf.h"

void	apply_percent(t_prtf *structprtf)
{
	if (structprtf->zero == 1)
		return;
	if (structprtf->precisionfound == 1)
		return;
	if (structprtf->width != 0)
	{
		if (structprtf->minus == 0)
		{
			print_recursiv(' ', ((structprtf->width) - 1));
			write(1, "%", 1);
		}
		if (structprtf->minus == 1)
		{
			write(1, "%", 1);
			print_recursiv(' ', ((structprtf->width) - 1));
		}
	}
	if (structprtf->minus == 1 && structprtf->precisionfound == 0 && structprtf->width == 0)
		write(1, "%", 1);
	if (structprtf->star == 0 && structprtf->zero == 0 && structprtf->minus == 0 && structprtf->width == 0 && structprtf->precisionfound == 0)
		write(1, "%", 1);
}
