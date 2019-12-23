#include "ft_printf.h"

#define TEST "[%5%]\n"

int main()
{

	char *str;
	char *str1;
	char c;
	int d;
	int e;
	unsigned int u;

	d = 51516141;
	u = 1089855;
	c = 'f';
	e = 100;
	str = "coucou";
	str1 = "hello";

	printf("=======MINE======\n");
	fflush(stdout);
	ft_printf(TEST);
	printf("=======VRAI======\n");
	printf(TEST);
	return (0);
}

