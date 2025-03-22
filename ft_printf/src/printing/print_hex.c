/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:58:25 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/13 08:47:51 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_precision_to_hex(char *num_str, int precision)
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

int	print_hex(unsigned int num, int uppercase, t_format *fmt)
{
	char	*num_str;
	int		total;
	int		len;

	num_str = ft_utoa_base(num, 16, uppercase);
	if (!num_str)
		return (0);
	if (fmt->precision >= 0)
	{
		num_str = apply_precision_to_hex(num_str, fmt->precision);
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
