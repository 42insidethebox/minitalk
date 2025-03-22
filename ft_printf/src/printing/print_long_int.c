/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:00:56 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/21 09:55:12 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_long_int(long n, t_format *fmt)
{
	char	*num_str;
	int		total_length;

	num_str = ft_ltoa(n);
	if (!num_str)
		return (0);
	if (fmt->precision > 0)
		num_str = apply_precision(n, num_str, fmt->precision);
	if (!num_str)
		return (0);
	apply_flags(&num_str, fmt);
	if (!num_str)
		return (0);
	total_length = ft_strlen(num_str);
	write(1, num_str, total_length);
	free(num_str);
	return (total_length);
}
