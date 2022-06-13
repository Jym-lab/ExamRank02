#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_print_str(char *str)
{
	int i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_print_base(long nbr, int base)
{
	int	count;
	int	n;

	count = 0;
	n = nbr % base;
	if (nbr / base > 0)
		count += ft_print_base(nbr / base, base);
	count += ft_putchar("0123456789abcdef"[n]);
	return (count);
}

int	ft_print_int(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	count += ft_print_base(nbr, 10);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		idx;
	int		count;
	va_list	args;

	idx = -1;
	count = 0;
	va_start(args, format);
	while (format[++idx])
	{
		if (format[idx] != '%')
			count += ft_putchar(format[idx]);
		if (format[idx] == '%' && format[idx + 1])
		{
			idx++;
			if (format[idx] == 's')
				count += ft_print_str(va_arg(args, char *));
			else if (format[idx] == 'd')
				count += ft_print_int(va_arg(args, int));
			else if (format[idx] == 'x')
				count += ft_print_base(va_arg(args, unsigned int), 16);
		}
	}
	va_end(args);
	return (count);
}
