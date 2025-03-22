/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:06:24 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/17 14:02:26 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_precision_to_unsigned(char *num_str, int precision)
{
	int		num_len;
	int		prec_zeros;
	char	*zeros;
	char	*new_str;

	num_len = ft_strlen(num_str);
	prec_zeros = precision - num_len;
	if (prec_zeros <= 0)
		return (num_str);
	zeros = malloc(prec_zeros + 1);
	if (!zeros)
	{
		free(num_str);
		return (NULL);
	}
	zeros[prec_zeros] = '\0';
	while (--prec_zeros >= 0)
		zeros[prec_zeros] = '0';
	new_str = ft_strjoin(zeros, num_str);
	free(zeros);
	free(num_str);
	return (new_str);
}

int	print_unsigned(unsigned int n, t_format *fmt)
{
	char	*num_str;
	int		total;
	int		len;

	num_str = ft_utoa_base(n, 10, 0);
	if (!num_str)
		return (0);
	if (fmt->precision >= 0)
	{
		num_str = apply_precision_to_unsigned(num_str, fmt->precision);
		if (!num_str)
			return (0);
	}
	apply_flags(&num_str, fmt);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	total = len;
	return (total);
}
