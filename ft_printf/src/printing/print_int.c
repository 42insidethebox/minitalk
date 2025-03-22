/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:01 by procha-r          #+#    #+#             */
/*   Updated: 2024/11/21 09:56:30 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n, t_format *fmt)
{
	char	*num_str;
	int		total;
	int		len;

	num_str = ft_itoa(n);
	if (!num_str)
		return (0);
	if (fmt->precision > 0)
		num_str = apply_precision(n, num_str, fmt->precision);
	if (!num_str)
		return (0);
	apply_flags(&num_str, fmt);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	total = len;
	return (total);
}
