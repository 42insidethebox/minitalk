/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:45:30 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/11 21:55:14 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	init_format(void)
{
	t_format	fmt;

	fmt.flag_minus = 0;
	fmt.flag_zero = 0;
	fmt.width = 0;
	fmt.precision = -1;
	fmt.specifier = '\0';
	return (fmt);
}

t_format	parse_format(const char **format)
{
	const char	*ptr;
	t_format	fmt;

	fmt = init_format();
	ptr = *format;
	parse_flag(&ptr, &fmt);
	parse_width(&ptr, &fmt);
	parse_precision(&ptr, &fmt);
	parse_specifier(&ptr, &fmt);
	*format = ptr;
	return (fmt);
}
