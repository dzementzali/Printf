#include "ft_printf.h"

void print_recursiv(char c, int n, t_prtf *structprtf)
{
	while (n > 0)
	{
		write(1, &c, 1);
		structprtf->len++;
		n--;
	}
}
void ft_putnbr(long nb, t_prtf *structprtf)
{
	if (nb < 10 && nb >= 0)
	ft_putprint(nb + 48, structprtf);
	else if (nb < 0)
	{
		ft_putprint('-', structprtf);
		ft_putnbr(nb * (-1), structprtf);
	}
	else
	{
		ft_putnbr(nb / 10, structprtf);
		ft_putnbr(nb % 10, structprtf);
	}
}
void ft_putnbr_unsigned(unsigned int n, t_prtf *structprtf)
{
	if (n < 10 && n >= 0)
		ft_putprint(n + 48, structprtf);
	else
	{
		ft_putnbr(n / 10, structprtf);
		ft_putnbr(n % 10, structprtf);
	}
}

//============================== Func affichage structur ==============================
void print_struct(t_prtf structprtf)
{
	printf("percent -> [%d]\n", structprtf.percent);
	printf("flag -> [%c]\n", structprtf.conv);
	printf("minus -> [%d]\n", structprtf.minus);
	printf("star -> [%d]\n", structprtf.star);
	printf("zero -> [%d]\n", structprtf.zero);
	printf("width -> [%d]\n", structprtf.width);
	printf("precision -> [%d]\n", structprtf.precision);
	printf("len -> [%d]\n", structprtf.len);
	printf("precisionfound -> [%d]\n", structprtf.precisionfound);
}
