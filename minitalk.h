/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:27:10 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/22 10:11:51 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# include "ft_printf/includes/ft_printf.h"
# include "ft_printf/libft/includes/libft.h"

typedef struct s_state
{
	int			bit_count;
	int			current_char;
	int			client_pid;
}				t_state;

#endif