/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:53:55 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/12 20:43:50 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag(const char **format, t_format *fmt)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			fmt->flag_minus = 1;
		if (**format == '0')
			fmt->flag_zero = 1;
		(*format)++;
	}
}
