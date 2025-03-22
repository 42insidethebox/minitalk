/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:52:09 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/21 09:55:02 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_prefix(int n)
{
	if (n < 0)
		return ("-");
	return ("");
}

char	*create_zeros(int prec_zeros)
{
	char	*zeros;
	int		i;

	zeros = malloc(prec_zeros + 1);
	if (!zeros)
		return (NULL);
	i = 0;
	while (i < prec_zeros)
	{
		zeros[i] = '0';
		i++;
	}
	zeros[prec_zeros] = '\0';
	return (zeros);
}

char	*apply_precision(int n, char *num_str, int precision)
{
	int		num_len;
	int		prec_zeros;
	char	*zeros;
	char	*temp;
	char	*new_num_str;

	num_len = ft_strlen(num_str);
	prec_zeros = precision - num_len;
	if (prec_zeros <= 0)
		return (num_str);
	zeros = create_zeros(prec_zeros);
	if (!zeros)
		return (NULL);
	temp = ft_strjoin(get_prefix(n), zeros);
	free(zeros);
	if (!temp)
		return (NULL);
	new_num_str = ft_strjoin(temp, num_str + (n < 0));
	free(temp);
	free(num_str);
	return (new_num_str);
}

int	count_long_digits(long n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_ltoa(long n)
{
	char			*str;
	int				len;
	unsigned long	nb;

	len = count_long_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		if (len == 0 && n < 0)
			str[len] = '-';
	}
	return (str);
}
