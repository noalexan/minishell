# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by noalexan          #+#    #+#              #
#    Updated: 2022/07/04 16:23:49 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		:= gcc
CFLAGS	:= -lreadline
OFLAGS	:= -Werror -Wextra -Wall

NAME	:= minishell

SRC		:=	src/main.c

OBJ		:= $(SRC:.c=.o)

LIB	:=

INCL	:=	include/minishell.h

GREEN	:= "\033[0m\033[1;32m"
CYAN	:= "\033[0m\033[1;36m"
YELLOW	:= "\033[0m\033[1;33m\033[3;33m"
RESET	:= "\033[0m"

RM		:= rm -rf

TEST    := 100

.c.o: $(SRC)
	@printf $(GREEN)"\r\033[KCompiling objects... "$(YELLOW)"<$<> "$(RESET)"⏳ "
	@$(CC) $(OFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@printf $(GREEN)"\r\033[KObjects compiled succesfully ✅\n"$(RESET)
	@printf $(CYAN)"\r\033[KCompiling '$(NAME)'... ⏳"$(RESET)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -I include/ -o $(NAME)
	@printf $(GREEN)"\r\033[KSuccess compiling '$(NAME)' ✅\n"$(RESET)

all: $(NAME)

load:
	@printf '\r █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 0%%\r'
	@sleep .01
	@printf '\r ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 5%%\r'
	@sleep .01
	@printf '\r ███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 10%%\r'
	@sleep .01
	@printf '\r ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 15%%\r'
	@sleep .01
	@printf '\r █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 20%%\r'
	@sleep .01
	@printf '\r ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 25%%\r'
	@sleep .01
	@printf '\r ███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 30%%\r'
	@sleep .01
	@printf '\r ████████▒▒▒▒▒▒▒▒▒▒▒▒▒ - 35%%\r'
	@sleep .01
	@printf '\r █████████▒▒▒▒▒▒▒▒▒▒▒▒ - 40%%\r'
	@sleep .01
	@printf '\r ██████████▒▒▒▒▒▒▒▒▒▒▒ - 45%%\r'
	@sleep .01
	@printf '\r ███████████▒▒▒▒▒▒▒▒▒▒ - 50%%\r'
	@sleep .01
	@printf '\r ████████████▒▒▒▒▒▒▒▒▒ - 55%%\r'
	@sleep .01
	@printf '\r █████████████▒▒▒▒▒▒▒▒ - 60%%\r'
	@sleep .01
	@printf '\r ██████████████▒▒▒▒▒▒▒ - 65%%\r'
	@sleep .01
	@printf '\r ███████████████▒▒▒▒▒▒ - 70%%\r'
	@sleep .01
	@printf '\r ████████████████▒▒▒▒▒ - 75%%\r'
	@sleep .01
	@printf '\r █████████████████▒▒▒▒ - 80%%\r'
	@sleep .01
	@printf '\r ██████████████████▒▒▒ - 85%%\r'
	@sleep .01
	@printf '\r ███████████████████▒▒ - 90%%\r'
	@sleep .01
	@printf '\r ████████████████████▒ - 95%%\r'
	@sleep .01
	@printf '\r █████████████████████ - 100%% \r'
	@sleep .08

clean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@$(RM) $(OBJ)
	@printf $(GREEN)"\r\033[Kcleaned 🗑\n"$(RESET)

fclean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@$(RM) $(OBJ)
	@printf $(CYAN)"\r\033[KErasing binary file... "$(RESET)"⏳ "
	@$(RM) $(NAME) test_parser
	@printf $(GREEN)"\r\033[KForce cleaned 🗑\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re
