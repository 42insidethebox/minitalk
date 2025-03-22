/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:55:45 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/12/08 23:07:03 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(const char **format, t_format *fmt)
{
	char	spec;

	spec = **format;
	if (spec == 'c' || spec == 's' || spec == 'd' || \
		spec == 'i' || spec == 'u' || spec == 'x' || \
		spec == 'X' || spec == 'p' || spec == '%')
	{
		fmt->specifier = spec;
		(*format)++;
	}
}
