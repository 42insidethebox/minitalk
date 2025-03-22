/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:16:36 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/13 08:47:43 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_pointer_to_str(void *ptr)
{
	unsigned long	address;
	char			*num_str;
	char			*prefixed_str;

	address = (unsigned long)ptr;
	num_str = ft_utoa_base(address, 16, 0);
	if (!num_str)
		return (NULL);
	prefixed_str = ft_strjoin("0x", num_str);
	free(num_str);
	return (prefixed_str);
}

int	print_pointer(void *ptr, t_format *fmt)
{
	char	*ptr_str;
	int		len;
	int		total;

	ptr_str = convert_pointer_to_str(ptr);
	if (!ptr_str)
		return (0);
	apply_flags(&ptr_str, fmt);
	len = ft_strlen(ptr_str);
	write(1, ptr_str, len);
	free(ptr_str);
	total = len;
	return (total);
}
