/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:13:44 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/11 21:38:44 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*allocate_buffer(int width)
{
	char	*str;
	int		i;

	str = malloc(width + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < width)
	{
		str[i] = ' ';
		i++;
	}
	str[width] = '\0';
	return (str);
}

static void	copy_string(char *dest, const char *src, \
	int len, int left_align)
{
	int	i;
	int	start;

	if (left_align)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		start = ft_strlen(dest) - len;
		i = 0;
		while (i < len)
		{
			dest[start + i] = src[i];
			i++;
		}
	}
}

int	print_string(const char *s, t_format *fmt)
{
	char	*str;
	int		len;
	int		width;
	int		total;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	if (fmt->width > len)
		width = fmt->width;
	else
		width = len;
	str = allocate_buffer(width);
	if (!str)
		return (0);
	copy_string(str, s, len, fmt->flag_minus);
	write(1, str, width);
	free(str);
	total = width;
	return (total);
}
