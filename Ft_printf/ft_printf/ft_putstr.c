#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len] != '\0')
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}
// #include<stdio.h>
// int main()
// {
// 	int i = ft_printf("  %%   ");
// 	printf("\n%d", i);
// }
