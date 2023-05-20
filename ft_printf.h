#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_check(char c, va_list *ap, int *len);
void	ft_print_char(char c, int *len);
void	ft_print_str(char *s, int *len);
void	ft_print_num(int num, int *len);
void	ft_print_ptr(uintptr_t ptr_hex, int *len);
void	ft_print_hex(unsigned int x, int *len, char check_x);
void	ft_print_unsignedint(unsigned int num, int *len);

#endif