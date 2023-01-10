# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2023/01/10 16:32:50 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SOURCE		=	push_swap.c push_swap_utils.c operations.c
OBJECT		=	$(SOURCE:.c=.o)

PRINTF			=	ft_printf/libftprintf.a
CC 				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f


all:			$(NAME) 
$(PRINTF):
						$(MAKE) -C ft_printf
$(NAME):		$(OBJECT) $(PRINTF)
						$(CC) $(CFLAGS) $(OBJECT) $(PRINTF) -o push_swap
						echo "Mandatory done"

clean:
						$(MAKE) clean -C ft_printf
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(MAKE) fclean -C ft_printf
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all

.SILENT: