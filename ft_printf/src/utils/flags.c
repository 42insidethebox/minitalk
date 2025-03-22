/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:03:41 by pedroribeir       #+#    #+#             */
/*   Updated: 2024/11/12 20:39:23 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*initialize_padding(int width, char pad_char)
{
	char	*new_str;
	int		i;

	new_str = malloc(width + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < width)
	{
		new_str[i] = pad_char;
		i++;
	}
	new_str[width] = '\0';
	return (new_str);
}

static void	copy_aligned_string(char *dest, const char *src, \
	int len, int left_align)
{
	if (left_align)
		ft_memcpy(dest, src, len);
	else
		ft_memcpy(dest + (ft_strlen(dest) - len), src, len);
}

static char	*apply_width(char *str, int width, \
	int left_align, char pad_char)
{
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	if (len >= width)
		return (str);
	new_str = initialize_padding(width, pad_char);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	copy_aligned_string(new_str, str, len, left_align);
	free(str);
	return (new_str);
}

void	apply_flags(char **str, t_format *fmt)
{
	char	pad_char;
	int		left_align;
	int		str_len;

	pad_char = ' ';
	left_align = fmt->flag_minus;
	if (fmt->flag_zero && !fmt->flag_minus && fmt->precision == -1)
		pad_char = '0';
	str_len = ft_strlen(*str);
	if (fmt->width > str_len)
	{
		*str = apply_width(*str, fmt->width, left_align, pad_char);
		if (!(*str))
			*str = NULL;
	}
}
