# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by Palmi             #+#    #+#              #
#    Updated: 2022/12/20 14:16:11 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CC		:= gcc
FLAGS	:= -Lvendor/readline/lib -lreadline -g
CFLAGS	:= -Werror -Wextra -Wall -g

# Name of the final executable
NAME	:= minishell

# All needed files
SRC		:=	src/🤖.c \
			src/env.c \
			src/main.c \
			src/utils.c \
			src/signal.c \
			src/history.c \
			src/parse_arg.c \
			src/create_pwd.c \
\
			src/error/error.c \
			src/error/lexer.c \
			src/error/redirection.c \
\
			src/builtins/cd.c \
			src/builtins/env.c \
			src/builtins/pwd.c \
			src/builtins/echo.c \
			src/builtins/exit.c \
			src/builtins/unset.c \
			src/builtins/export.c \
\
			src/operator/pipe.c \
			src/operator/lexer.c \
			src/operator/utils.c \
			src/operator/verify.c \
			src/operator/heredoc.c \
			src/operator/expender.c \
			src/operator/redirection.c \
\
			src/execute/utils.c \
			src/execute/execute.c \
\
			src/fun/the_messager.c \

OBJ		:= $(SRC:.c=.o)

# All needed library
LIB		:=	src/libft/libft.a \
			src/printf/printf.a \
			src/get_next_line/get_next_line.a \

# Colors for differents prints
GREEN	:= "\033[0m\033[1;32m"
CYAN	:= "\033[0m\033[1;36m"
YELLOW	:= "\033[0m\033[1;33m\033[3;33m"
RESET	:= "\033[0m"

# Compile all .c files
.c.o: $(SRC)
	@printf $(GREEN)"\r\033[KCompiling objects... "$(YELLOW)"<$<> ⏳ "$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# Compile all .o files
$(NAME): vendor/readline $(OBJ)
	@printf $(GREEN)"\r\033[KObjects compiled succesfully ✅\n"$(RESET)
	@make -C src/libft
	@make -C src/printf
	@make -C src/get_next_line
	@printf $(CYAN)"\r\033[KCompiling '$(NAME)'... ⏳"$(RESET)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -I include/ -o $(NAME)
	@printf $(GREEN)"\r\033[KSuccess compiling '$(NAME)' ✅\n"$(RESET)
	@printf "\n"
	@printf "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\n"
	@printf "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\n"
	@printf "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\n"
	@printf "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\n"
	@printf "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n"
	@printf "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"
	@printf "\n"
	@printf "██████╗  ██████╗ ██╗     ███╗   ██╗ █████╗ ██████╗ ███████╗███████╗███████╗\n"
	@printf "██╔══██╗██╔═══██╗██║     ████╗  ██║██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝\n"
	@printf "██████╔╝██║   ██║██║     ██╔██╗ ██║███████║██████╔╝█████╗  █████╗  █████╗\n"
	@printf "██╔═══╝ ██║   ██║██║     ██║╚██╗██║██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██╔══╝\n"
	@printf "██║     ╚██████╔╝███████╗██║ ╚████║██║  ██║██║  ██║███████╗██║     ██║\n"
	@printf "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n"
	@printf "\n"

# Readline
vendor/readline: vendor
	@if [ ! -d "vendor/readline" ]; then \
		printf $(CYAN)"\r\033[KInstallation of readline... ⏳\n"$(RESET); \
		curl https://raw.githubusercontent.com/noalexan/minishell/stable/install_readline.sh | sh; \
	fi

# Vendor
vendor:
	@mkdir vendor

# Default command to launch
all: $(NAME) # load

# Compile and run minishell
run: all
	@./$(NAME)

shortcut:
	@open https://www.google.com/search?q=how+to+become+a+good+developer+%3\
	F&rlz=1C5CHFA_enFR1031FR1031&ei=typxY8mBN-yUxc8Pm6CB4Ak&ved=0ahUKEwiJud\
	LQ2Kv7AhVsSvEDHRtQAJwQ4dUDCA8&uact=5&oq=how+to+become+a+good+developer+\
	%3F&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIHCAAQgAQQEzIGCAAQHhATMgYIABAeEBMyBggA\
	EB4QEzIICAAQCBAeEBMyCAgAEAgQHhATMggIABAIEB4QEzIICAAQCBAeEBMyCAgAEAgQHhA\
	TMggIABAIEB4QEzoKCAAQRxDWBBCwAzoJCAAQgAQQDRATOggIABAeEA0QEzoICAAQFhAeEB\
	NKBAhNGAFKBAhBGABKBAhGGABQhgpYnDJgvTdoAXABeACAAWaIAe0BkgEDMi4xmAEAoAEBy\
	AEIwAEB&sclient=gws-wiz-serp

# Print our god
polnareff:
	@echo ""
	@echo "                            . ...**/##/***.,,*,                                 "
	@echo "                        ,.****//(#(#.###%((//(###(*/*(/*                        "
	@echo "                  .,.,,.*/((#%#(&((%%/*&&&#(//(/(##//(//((                      "
	@echo "                ,,,,.,,*//#/%###%#%(#(%&&/(##((##/*#(/**((((*                   "
	@echo "               .,,.*,*/,*/%(#&##%(/(%%(((#(#((//////(/(/*(//(//                 "
	@echo "              .,.,.,/..//,,/,/#%((#(**//////#((///(/*#//,/(//////               "
	@echo "            ,....,,*/.,.*/(#*/%#(//*(*///(/(#/#*(%,/,/#(/**/*/((/*.             "
	@echo "            .....,,*,**,*((*/,#((/(,*,,*/.(**(/,///////(((#(*(./(/(/            "
	@echo "           ...,,*,.,././//////,///*/*/,,,,..,*,*//(((,/##/(//*/,(#(**.          "
	@echo "           ...,*,,,,/**(/,.,*(*/,**.,**,.,****,,*/***,**((##(##*(*//*/          "
	@echo "          ..,...,.***/*,,..*,***,*,,.,,,.*,*/*,*,,*/*,****/*/#(*(///,,,         "
	@echo "         .,..,/.,*,**/,/,*/,***,*/,*,.,,.,..,,.****/,*******///*/(**//**        "
	@echo "          .,,,,*,(/*,//*****/*,,*******//*,**//**,**(/,***/(*,*((***/*,**.      "
	@echo "          ,.*.**,*((*,((#((/(##//////(#%%*. ./(#%###(...*,**((#,***,*****       "
	@echo "          ,,..//(/,,,,,**,.  .*(&&*...*&&&@@@@&@@&&&&.,*%/*/((//**(/////*,      "
	@echo "       .....,,*/***#@@@@@@@@@&%,,.....%#&@@&&@&&&%&&@. (%//,***,,/*((,,**,.     "
	@echo "        .,.,,**/(#*,%&@@@@@@@&&% *,.,..%%%%%%%%%&&%(..,*(***///*.(*/*/,,,**     "
	@echo "         .,.,,.**#(.*(&&&&&&%%%&.*,.... .*(((*,   *#(,,,/****#//,,****.*,,.     "
	@echo "          ,..,,,**/(#* .*/(*. .//,,..,.../(#####(/*,,,,/****,**./(/,/**,,*      "
	@echo "            ,.,*,***(#%(#####%#%%/*,,*#*....,..,,,,,,,,//(/*/(/,.///****,,.     "
	@echo "            .,...,,/*((((##(//(#%%%%%*.,,,...,,,,,,,,,,*(&//(%/(*,(/******,.    "
	@echo "            ..,..,,,**/*(#((//(##((*,///*,,*/,,,,,,,,**/%(&%(//#////********.   "
	@echo "             .,,,,//**////(#(((#%%(/*,,,,,,,,,*******/((#%/%&/(*/**/////**,,    "
	@echo "               ..,,,,.*/*(#/(#(#((((////**,,,,,,***/#(//#&&%%(*,(,***,**/**//   "
	@echo "               .,..,,.,**(####(#(/*,,,,,.,.,,,,*((#(//*/(%#%/(/**//,,,,,*/*///(("
	@echo "               ...,..,,,*(((/#%#(((/*********((##(//****/(##(/*,/,,*,*,,*,//////"
	@echo "               ,,,,**,,*/(##(&%###%########%%##(/********/(/((/**,**,,**////(///"
	@echo "         .......*(**#**/*//((&&#(%%%%##%%%%##(//****,,***/(///*.,,,*,*((/(//((//"
	@echo "   ..........,,..,#%%##%&&%%&&&&(##@@&&%%%%%#((/****,,****/(/*,*,,,*#(((/((//(/("
	@echo ""

# Just a cute loading bar
load:
	@printf '\r █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 0%%\r'
	@sleep .1
	@printf '\r ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 5%%\r'
	@sleep .1
	@printf '\r ███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 10%%\r'
	@sleep .1
	@printf '\r ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 15%%\r'
	@sleep .1
	@printf '\r █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 20%%\r'
	@sleep .1
	@printf '\r ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 25%%\r'
	@sleep .1
	@printf '\r ███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 30%%\r'
	@sleep .1
	@printf '\r ████████▒▒▒▒▒▒▒▒▒▒▒▒▒ - 35%%\r'
	@sleep .1
	@printf '\r █████████▒▒▒▒▒▒▒▒▒▒▒▒ - 40%%\r'
	@sleep .1
	@printf '\r ██████████▒▒▒▒▒▒▒▒▒▒▒ - 45%%\r'
	@sleep .1
	@printf '\r ███████████▒▒▒▒▒▒▒▒▒▒ - 50%%\r'
	@sleep .1
	@printf '\r ████████████▒▒▒▒▒▒▒▒▒ - 55%%\r'
	@sleep .1
	@printf '\r █████████████▒▒▒▒▒▒▒▒ - 60%%\r'
	@sleep .1
	@printf '\r ██████████████▒▒▒▒▒▒▒ - 65%%\r'
	@sleep .1
	@printf '\r ███████████████▒▒▒▒▒▒ - 70%%\r'
	@sleep .1
	@printf '\r ████████████████▒▒▒▒▒ - 75%%\r'
	@sleep .1
	@printf '\r █████████████████▒▒▒▒ - 80%%\r'
	@sleep .1
	@printf '\r ██████████████████▒▒▒ - 85%%\r'
	@sleep .1
	@printf '\r ███████████████████▒▒ - 90%%\r'
	@sleep .1
	@printf '\r ████████████████████▒ - 95%%\r'
	@sleep .1
	@printf '\r █████████████████████ - 100%%\r'
	@sleep .8

# Clean all .o and .a files
clean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@rm -rdf $(OBJ)
	@make -C src/libft clean
	@make -C src/printf clean
	@make -C src/get_next_line clean
	@printf $(GREEN)"\r\033[Kcleaned 🗑\n"$(RESET)

# Same as 'clean' but clean minishell too
fclean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@rm -rdf $(OBJ)
	@make -C src/libft fclean
	@make -C src/printf fclean
	@make -C src/get_next_line fclean
	@printf $(GREEN)"\r\033[KObjects cleaned 🗑\n"$(RESET)
	@printf $(CYAN)"\r\033[KErasing binary file... "$(RESET)"⏳ "
	@rm -rdf $(NAME) test_parser
	@printf $(GREEN)"\r\033[KBinary file cleaned 🗑\n"$(RESET)
	@printf $(GREEN)"\r\033[KForce cleaned 🗑\n"$(RESET)

# Clean readline
fclean_readline:
	@printf $(CYAN)"\r\033[KErasing readline... "$(RESET)"⏳ "
	@rm -rdf vendor
	@printf $(GREEN)"\r\033[KReadline cleaned 🗑\n"$(RESET)

# Clean all and recompile minishell
re: fclean all

.PHONY: all clean fclean re polnareff load fclean_readline run readline
