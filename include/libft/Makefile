# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2023/05/18 00:19:54 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		= srcs/
SRCS_FILES		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				  ft_strchr.c ft_strrchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				  ft_strncmp.c ft_strnstr.c ft_substr.c ft_tolower.c ft_toupper.c\
				  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c\
				  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
				  ft_putnbr_fd.c ft_split.c	
SRCS 			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

BONUS_SRCS_FILES= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS_BONUS		= $(addprefix $(SRCS_DIR), $(BONUS_SRCS_FILES))

OBJS_DIR		= objs/
OBJS 			= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))


BONUS_OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) ${CFLAGS} -Iinclude/  -c $< -o $@

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

NAME			= libft.a

all:			objs $(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

bonus:			all $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

objs:			
				mkdir -p objs			

.PHONY:			all clean fclean re 