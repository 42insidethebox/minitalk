/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:51:32 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/12 20:42:00 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(const char **format, t_format *fmt)
{
	int	width;

	width = 0;
	while (**format >= '0' && **format <= '9')
	{
		width = width * 10 + (**format - '0');
		(*format)++;
	}
	fmt->width = width;
}

void	parse_precision(const char **format, t_format *fmt)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		precision = 0;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			precision = precision * 10 + (**format - '0');
			(*format)++;
		}
	}
	fmt->precision = precision;
}
