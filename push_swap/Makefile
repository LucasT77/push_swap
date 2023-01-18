# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/01/18 17:03:14 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SOURCE		=	push_swap.c push_swap_utils.c operations.c selector.c sort_5_or_less.c
OBJECT		=	$(SOURCE:.c=.o)

LIBFT			=	libft/libft.a
CC 				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f


all:			$(NAME) 
$(LIBFT):
						$(MAKE) -C libft
$(NAME):		$(OBJECT) $(LIBFT)
						$(CC) $(CFLAGS) $(OBJECT) $(LIBFT) -o push_swap
						echo "Mandatory done"

clean:
						$(MAKE) clean -C libft
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(MAKE) fclean -C libft
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all

.SILENT:
