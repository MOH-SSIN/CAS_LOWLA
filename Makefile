# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 14:30:14 by mez-zahi          #+#    #+#              #
#    Updated: 2025/02/09 17:10:04 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c chker_erreur.c concat_arg.c\
	creat_pile.c afficher_pile.c\
	free.c\
	lis.c\
	push_swap_utils.c \
	operation/push.c operation/reverse_rotate.c operation/rotate.c operation/swap.c \
	ptit_piles.c\
	case_grand_pile.c \
	init_pile.c\
	move_pile.c \
	
OBJ = $(SRC:.c=.o)

# CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

HEADER = push_swap.h
DIR_OBJ = rep_clean

PATH_LIBFT = ./libft
LIBFT = $(PATH_LIBFT)/libft.a


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@mkdir -p $(DIR_OBJ) && mv $(OBJ) $(DIR_OBJ)
	
%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ) : $(HEADER)

clean :
	@$(RM) $(OBJ) $(DIR_OBJ)
	@make -C $(PATH_LIBFT) clean

fclean : clean
	@$(RM) $(NAME)
	@make -C $(PATH_LIBFT) fclean

re : fclean all

.PHONY : clean all