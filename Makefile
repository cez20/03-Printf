# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2023/05/17 22:50:26 by cemenjiv         ###   ########.fr        #
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
				$(CC) ${CFLAGS}  -c $< -o $@

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











# SRCS			= ft_printf.c ft_printf_hex.c ft_printf_nbr.c ft_printf_str.c
				 
# OBJS			= $(SRCS:.c=.o)

# NORM 			= norminette

# CC				= gcc
# CFLAGS			= -Wall -Wextra -Werror
# RM				= rm -f

# NAME			= libftprintf.a

# all:			$(NAME)

# $(NAME):		$(OBJS)
# 				$(MAKE) bonus -C ./libft
# 				cp libft/libft.a $(NAME)
# 				ar rcs $(NAME) $(OBJS)
# 				ranlib $(NAME)
				
# clean:		
# 				$(MAKE) clean -C ./libft
# 				$(RM) -f $(OBJS)
				
# fclean:			clean
# 				$(MAKE) fclean -C ./libft
# 				$(RM) $(NAME)
				
# re:				fclean all
				



