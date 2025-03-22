/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:55:37 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/14 09:04:58 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*allocate_padded_char(char c, int width, int left_align)
{
	char	*str;
	int		i;

	str = malloc(width + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < width)
	{
		if (left_align && i == 0)
			str[i] = c;
		else if (!left_align && i == width - 1)
			str[i] = c;
		else
			str[i] = ' ';
		i++;
	}
	return (str);
}

int	print_char(char c, t_format *fmt)
{
	char	*str;
	int		width;
	int		total;

	width = 1;
	if (fmt->width > 1)
		width = fmt->width;
	str = allocate_padded_char(c, width, fmt->flag_minus);
	if (!str)
		return (0);
	write(1, str, width);
	free(str);
	total = width;
	return (total);
}
