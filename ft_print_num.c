#include "ft_printf.h"

void	ft_print_ptr(uintptr_t ptr_hex, int *len)
{
	int		i;
	char	*hex_char;
	char	str[16];

	hex_char = "0123456789abcdef";
	write(1, "0x", 2);
	(*len) = (*len) + 2;
	if (ptr_hex == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	i = 0;
	while (ptr_hex != 0)
	{
		str[i] = hex_char[ptr_hex % 16];
		ptr_hex = ptr_hex / 16;
		i++;
	}
	while (i != 0)
		ft_print_char(str[--i], len);
}

void	ft_print_num(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) = (*len) + 11;
		return ;
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		(*len)++;
		num = num * -1;
		ft_print_num(num, len);
	}
	else if (num > 9)
	{
		ft_print_num(num / 10, len);
		ft_print_num(num % 10, len);
	}
	else
		ft_print_char((num + '0'), len);
}

void	ft_print_unsignedint(unsigned int num, int *len)
{
	if (num > 9)
	{
		ft_print_unsignedint(num / 10, len);
		ft_print_unsignedint(num % 10, len);
	}
	else
		ft_print_char((num + '0'), len);
}

void	ft_print_hex(unsigned int x, int *len, char check_x)
{
	int		i;
	char	*hex_char;
	char	str[16];

	if (check_x == 'x')
		hex_char = "0123456789abcdef";
	else if (check_x == 'X')
		hex_char = "0123456789ABCDEF";
	if (x == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	i = 0;
	while (x != 0)
	{
		str[i] = hex_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i != 0)
		ft_print_char(str[--i], len);
}