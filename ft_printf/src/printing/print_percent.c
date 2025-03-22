/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:21:15 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/13 08:46:01 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_format *fmt)
{
	char	*str;
	int		len;
	int		total;

	str = ft_strdup("%");
	if (!str)
		return (0);
	apply_flags(&str, fmt);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	total = len;
	return (total);
}
