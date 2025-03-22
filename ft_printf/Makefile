# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 16:03:19 by procha-r          #+#    #+#              #
#    Updated: 2025/03/22 10:25:00 by pedroribeir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# Directories
SRCDIR      = src
LIBFTDIR    = libft
INCDIR      = includes
LIBFTINCDIR = $(LIBFTDIR)/includes

# Source files
SRC         = $(SRCDIR)/ft_printf.c \
              $(SRCDIR)/parsing/init_format.c \
              $(SRCDIR)/parsing/parse_flags.c \
              $(SRCDIR)/parsing/parse_specifier.c \
              $(SRCDIR)/parsing/parse_width_precision.c \
              $(SRCDIR)/printing/print_char.c \
              $(SRCDIR)/printing/print_hex.c \
              $(SRCDIR)/printing/print_int.c \
               $(SRCDIR)/printing/print_long_int.c \
              $(SRCDIR)/printing/print_percent.c \
              $(SRCDIR)/printing/print_pointer.c \
              $(SRCDIR)/printing/print_string.c \
              $(SRCDIR)/printing/print_unsigned.c \
              $(SRCDIR)/utils/flags.c \
              $(SRCDIR)/utils/format_helpers.c \
			  $(SRCDIR)/utils/print_int_utils.c \
              $(LIBFTDIR)/src/ft_bzero.c \
              $(LIBFTDIR)/src/ft_itoa.c \
              $(LIBFTDIR)/src/ft_memcpy.c \
              $(LIBFTDIR)/src/ft_memset.c \
              $(LIBFTDIR)/src/ft_strcpy.c \
              $(LIBFTDIR)/src/ft_strdup.c \
              $(LIBFTDIR)/src/ft_strjoin.c \
              $(LIBFTDIR)/src/ft_strlen.c \
              $(LIBFTDIR)/src/ft_strncpy.c \
               $(LIBFTDIR)/src/ft_atoi.c \
              $(LIBFTDIR)/src/ft_utoa_base.c

# Object files
OBJ         = $(SRC:.c=.o)

# Include directories
INCLUDES    = -I$(INCDIR) -I$(LIBFTINCDIR)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
