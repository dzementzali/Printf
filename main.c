#include "ft_printf.h"
#include <stdio.h>

#define TEST "[%4.*s]\n"
int main()
{

	char *str;
	char *str1;
	char c;
	int d;
	int e;
	unsigned int u;

	d = 5155580;
	u = 1089855;
	c = 'f';
	e = 100;
	str = "yolo";
	str1 = "world";
	printf("=======MINE======\n");
	fflush(stdout);
	printf("result -> %d\n", ft_printf(TEST, -1, str));
	printf("=======VRAI======\n");
	printf("result -> %d\n", printf(TEST, -1, str));
	return (0);
}
