# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2021/12/07 09:54:28 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c ft_printf_utils.c
				 
OBJS			= $(SRCS:.c=.o)

NORM 			= norminette

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)
				
clean:			
				$(MAKE) clean -C ./libft
				$(RM) -f $(OBJS)
				
fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
				



