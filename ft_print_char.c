#include "ft_printf.h"

void	ft_print_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_print_str(char *s, int *len)
{
	int		i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*len) = (*len) + 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		(*len)++;
		i++;
	}
}