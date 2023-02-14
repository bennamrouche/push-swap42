# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 16:36:14 by ebennamr          #+#    #+#              #
#    Updated: 2023/02/14 16:36:29 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## Variable Block ###############
CC = cc
NAME = push_swap
FLAG = -Wall -Wextra -Werror
MAN = pushswap.c
BNS = ft_checker.c
BONS_NAME = checker
SRC:= algo_anayls.c  string3.c  lis_algo.c  string2.c \
		algo_excute.c  instruction1.c      util.c \
		array.c  instruction2.c string1.c

INCLIDE = pushswap.h
OBJ_MAN = $(SRC:.c=.o)  $(MAN:.c=.o)
OBJ_BNS = $(SRC:.c=.o)  $(BNS:.c=.o)
########### shell color ############
GREEN:=\033[0;32m
RED =\033[0;31m
RESET =\033[0m
XR = \033[0m
XG = \033[32;7m
MARK = "✅"
REMOVE = "🗑"
############## Traget Block ###############
all : $(NAME)

$(NAME) :print $(OBJ_MAN)
	@echo "$(MARK)Object File Created"
	@$(CC) $(FLAG) $(OBJ_MAN) -o $(NAME)
	@echo "$(MARK) push_swap Created"

bonus:print $(OBJ_BNS)
	@echo "$(MARK)Object File Created"
	@$(CC) $(FLAG) $(FRAMEWORK) $(OBJ_BNS) -o $(BONS_NAME)
	@echo "$(MARK) checker  Created"

%.o:%.c $(INCLIDE)
	@$(CC) $(FLAG) -c $< -o $@
	@echo "$(MARK) $@"
clean:
	@echo "$(RED) $(REMOVE) Rmove Oject Files $(RESET)"
	@rm -rf $(OBJ_MAN) $(OBJ_BNS)


fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONS_NAME)
	@echo "$(RED) $(REMOVE) Remove $(NAME) $(RESET)"
	@echo "$(GREEN) Done $(RESET)"

re: fclean all

print:
	@echo "$(RED)┌─┐┬ ┬┌─┐┬ ┬   ┌─┐┬ ┬┌─┐┌─┐"
	@echo		"├─┘│ │└─┐├─┤───└─┐│││├─┤├─┘"
	@echo		"┴  └─┘└─┘┴ ┴   └─┘└┴┘┴ ┴┴$(RESET)"
PHONY: re fclean clean all
