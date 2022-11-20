#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10)
	{
		len += ft_putchar(nb + 48);
	}
	else
	{
		len += ft_putnbr_u(nb / 10);
		len += ft_putnbr_u(nb % 10);
	}
	return (len);
}
