# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 14:09:36 by galambey          #+#    #+#              #
#    Updated: 2023/06/23 16:47:22 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= megalibft.a
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror

################################### LIBRARIES ###################################

PATH_LIBFT 		=	./ft_printf/LIBFT 
PATH_PRINTF 	=	./ft_printf
PATH_GNL 		=	./get_next_line 

LIBFT			=	libft.a
LIBFT_PRINTF	=	libftprintf.a
LIBFT_GNL		=	get_next_line.a

#################################### RULES ####################################

all: $(NAME)

$(NAME):	
	make -C $(PATH_PRINTF)
	make -C $(PATH_GNL)
	mv ./ft_printf/LIBFT/libft.a ./libft.a
	mv ./ft_printf/libftprintf.a ./libftprintf.a
	mv ./get_next_line/get_next_line.a ./get_next_line.a
	ar -rcT $(NAME) $(LIBFT) $(LIBFT_PRINTF) $(LIBFT_GNL)

clean:
	make -sC $(PATH_PRINTF) clean
	make -sC $(PATH_GNL) clean

fclean: clean
	make -sC $(PATH_PRINTF) fclean
	make -sC $(PATH_GNL) fclean
	rm -f *.a

re: fclean
	make all

.PHONY: all clean fclean re