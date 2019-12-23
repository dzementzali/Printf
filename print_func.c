#include "ft_printf.h"

void print_recursiv(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr(int nb)
{
	long n;

	n = nb;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}

	if (n < 9)
	{
		ft_putchar(n + 48);
	}

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}
void ft_putnbr_unsigned(unsigned int n)
{
	if (n < 9)
	{
		ft_putchar(n + 48);
	}

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}
void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

//============================== Func affichage structur ==============================
void print_struct(t_prtf structprtf)
{
	printf("percent -> [%d]\n", structprtf.percent);
	printf("flag -> [%c]\n", structprtf.flag);
	printf("minus -> [%d]\n", structprtf.minus);
	printf("star -> [%d]\n", structprtf.star);
	printf("zero -> [%d]\n", structprtf.zero);
	printf("width -> [%d]\n", structprtf.width);
	printf("precision -> [%d]\n", structprtf.precision);
	printf("len -> [%d]\n", structprtf.len);
	printf("precisionfound -> [%d]\n", structprtf.precisionfound);
}
