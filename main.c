#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("ft_printf() => ");
	ft_printf("String: %s, Decimal: %d, Hexadecimal: %x / %x\n", "42Exam", -42, 42, -42);

	printf("printf() => ");
	printf("String: %s, Decimal: %d, Hexadecimal: %x / %x\n", "42Exam", -42, 42, -42);

	printf("\n============================\n\n");

	ft_printf("ft_printf() => ");
	ft_printf("Magic %s is %d\n", "number", 42);

	printf("printf() => ");
	printf("Magic %s is %d\n", "number", 42);

	printf("\n============================\n\n");

	ft_printf("ft_printf() => ");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	printf("printf() => ");
	printf("Hexadecimal for %d is %x\n", 42, 42);
}
