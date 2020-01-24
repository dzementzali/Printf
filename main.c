#include "ft_printf.h"

#define TEST "[%10.5i]\n"
int main()
{

	char *str;
	char *str1;
	char c;
	int d;
	int e;
	unsigned int u;

	d = -5155580;
	u = 1089855;
	c = 'f';
	e = 100;
	str = "yolo00";
	str1 = "world";
	printf("=======MINE======\n");
	fflush(stdout);
	printf("result -> %d\n", ft_printf(TEST, -946));
	printf("=======VRAI======\n");
	printf("result -> %d\n", printf(TEST, -946));
	return (0);
}
