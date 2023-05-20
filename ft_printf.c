#include "ft_printf.h"

void	ft_check(char c, va_list *ap, int *len)
{
	if (c == 'c')
		ft_print_char(va_arg(*ap, int), len);
	else if (c == 's')
		ft_print_str(va_arg(*ap, char *), len);
	else if (c == 'p')
		ft_print_ptr(va_arg(*ap, uintptr_t), len);
	else if (c == 'd' || c == 'i')
		ft_print_num(va_arg(*ap, int), len);
	else if (c == 'u')
		ft_print_unsignedint(va_arg(*ap, unsigned int), len);
	else if (c == 'x')
		ft_print_hex(va_arg(*ap, unsigned int), len, 'x');
	else if (c == 'X')
		ft_print_hex(va_arg(*ap, unsigned int), len, 'X');
	else if (c == '%')
		ft_print_char('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			len;

	va_start(ap, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_check(str[i], &ap, &len);
			i++;
		}
		else
		{
			ft_print_char(str[i], &len);
			i++;
		}
	}
	va_end(ap);
	return (len);
}

// #include <stdio.h>
// int main ()
// {
// 	ft_printf("ft_printf : %c %c \n", '0', '1');
// 	printf("printf : %c %c\n", '0', '1');

// // 	// char str[10] = "String";
// // 	// ft_printf("ft_printf : %s \n", str);
// // 	// printf("printf : %s \n", str);

// }