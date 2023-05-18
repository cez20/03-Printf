# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2023/05/17 23:40:01 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS_DIR		= srcs/
SRCS_FILES		= ft_printf.c ft_printf_hex.c ft_printf_nbr.c ft_printf_str.c
SRCS 			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR		= objs/
OBJS 			= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

BONUS_OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))
BONUS           = get_next_line

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) ${CFLAGS} -I./include/ft_printf -c $< -o $@

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

all:			objs $(NAME)

$(NAME):		$(OBJS)
				$(MAKE) bonus -C include/libft	
				cp include/libft/libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(MAKE) fclean -C ./include/libft
				$(RM) $(NAME)
				
re:				fclean all

objs:			
				mkdir -p objs			

.PHONY:			all clean fclean re bonus
