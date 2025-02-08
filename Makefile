# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 14:30:14 by mez-zahi          #+#    #+#              #
#    Updated: 2025/02/08 16:55:35 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c chker_erreur.c concat_arg.c

OBJ = $(SRC:.c=.o)

# CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

HEADER = push_swap.h
DIR_OBJ = rep_clean

PATH_LIBFT = ./libft
LIBFT = $(PATH_LIBFT)/libft.a

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@mkdir -p $(DIR_OBJ) && mv $(OBJ) $(DIR_OBJ)
	

clean :
	@$(RM) $(OBJ) $(DIR_OBJ)
	@make -C $(PATH_LIBFT) clean

fclean : clean
	@$(RM) $(NAME)
	@make -C $(PATH_LIBFT) fclean

re : fclean all

.PHONY : clean all