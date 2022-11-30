# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:16:03 by albrusso          #+#    #+#              #
#    Updated: 2022/11/14 15:35:52 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_is_c.c ft_is_d_or_i.c ft_is_p.c ft_is_s.c ft_is_u.c \
				ft_is_x_or_X.c ft_itoa.c ft_strlen.c ft_printf.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

PHONY:			all clean fclean re
