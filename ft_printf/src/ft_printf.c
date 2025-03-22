/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:02:13 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/17 16:58:23 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	handle_specifier(t_format fmt, va_list *args)
{
	int	length;

	length = 0;
	if (fmt.specifier == 'c')
		length = print_char(va_arg(*args, int), &fmt);
	else if (fmt.specifier == 's')
		length = print_string(va_arg(*args, char *), &fmt);
	else if (fmt.specifier == 'd' || fmt.specifier == 'i')
	{
		if (fmt.length_modifier == 'l')
			length = print_long_int(va_arg(*args, long), &fmt);
		else
			length = print_int(va_arg(*args, int), &fmt);
	}
	else if (fmt.specifier == 'x' || fmt.specifier == 'X')
		length = print_hex(va_arg(*args, unsigned int), \
		(fmt.specifier == 'X'), &fmt);
	else if (fmt.specifier == 'p')
		length = print_pointer(va_arg(*args, void *), &fmt);
	else if (fmt.specifier == 'u')
		length = print_unsigned(va_arg(*args, unsigned int), &fmt);
	else if (fmt.specifier == '%')
		length = print_percent(&fmt);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			total_length;
	const char	*ptr;
	t_format	fmt;

	total_length = 0;
	ptr = format;
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			fmt = parse_format(&ptr);
			total_length += handle_specifier(fmt, &args);
		}
		else
		{
			write(1, ptr, 1);
			total_length++;
			ptr++;
		}
	}
	va_end(args);
	return (total_length);
}
