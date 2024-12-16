# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 11:40:45 by galambey          #+#    #+#              #
#    Updated: 2023/08/31 16:57:42 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

################################### SOURCES ###################################

SRCS		=	srcs/get_next_line.c \
				srcs/get_next_line_multifd.c \
				srcs/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_DIR = objs

#################################### RULES ####################################

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $(OBJS)
	mkdir $(OBJS_DIR)
	mv srcs/*.o $(OBJS_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean :    clean
	      rm -f $(NAME)

re : fclean
	make all

.PHONY :  all clean fclean re