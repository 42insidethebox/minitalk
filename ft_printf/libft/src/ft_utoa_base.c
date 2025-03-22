/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:10:48 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/14 09:06:50 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen_base(unsigned long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long num, int base, int uppercase)
{
	char	*str;
	char	*digits;
	int		len;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = ft_numlen_base(num, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[--len] = digits[num % base];
		num /= base;
	}
	return (str);
}
