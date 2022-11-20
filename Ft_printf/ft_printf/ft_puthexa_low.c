#include "ft_printf.h"

int	ft_puthexa_low(unsigned long long n)
{
	char	*hex_down;
	int		len;

	len = 0;
	hex_down = "0123456789abcdef";
	if (n < 16)
	{
		len += write (1, hex_down + n, 1);
	}
	if (n >= 16)
	{	
		len += ft_puthexa_low (n / 16);
		len += ft_puthexa_low (n % 16);
	}
	return (len);
}
