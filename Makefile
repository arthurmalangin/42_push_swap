# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 19:20:25 by amalangi          #+#    #+#              #
#    Updated: 2024/01/19 19:11:33 by amalangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =		push_swap

CC              =       cc

FLAG            =       -g

LIBFT_FILE      =		libft.a

LIBFT_PATH      =       ./libft/

LIBFT_LIB       =       $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

LIBFT_EX        =       $(LIBFT_LIB) $(FLAG)

C_FILE          =       main.c	\
						simplify_stack.c	\
						sort.c	\
						exit.c	\
						instruction/instruction_handler_double.c	\
						instruction/instruction_handler_move.c	\
						instruction/instruction_handler_rotate.c	\
						instruction/push.c	\
						instruction/reverse_rotate_both.c	\
						instruction/reverse_rotate.c	\
						instruction/rotate_both.c	\
						instruction/rotate.c	\
						instruction/swap_both.c	\
						instruction/swap.c	\
						parsing/check_param.c	\
						parsing/doublon.c	\
						parsing/fill_stack.c	\
						parsing/join_free.c	\
						parsing/parsing_utils.c	\
						sort_utils/info_getter.c	\
						sort_utils/sort_helper.c	\
						sort_utils/sort_instruction.c	\


SRC_DIR         =       ./src/

INC_DIR         =       ./includes/

SRC 			=		$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			    =		$(SRC:.c=.o)

.c.o:
		$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

./libft/libft.a:
		@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)...\n"
		@make -sC $(LIBFT_PATH)
		@echo "\033[1;32mLIBFT created\033[0m\n"

$(NAME): ./libft/libft.a $(OBJ)
		@echo "\033[0;33m\nCOMPILING PUSH_SWAP...\n"
		$(CC) $(OBJ) $(LIBFT_EX) -o $(NAME)
		@echo "\033[1;32m./push_swap created\033[0m\n"

clean:
		@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
		@make clean -sC $(LIBFT_PATH)
		@echo "\033[1;32mDone\n"
		@echo "\033[0;31mDeleting all object...\n"
		@rm -f $(OBJ) $(NAME)
		@echo "\033[1;32mDone\033[0m\n"

fclean: clean
		@echo "\033[0;31mDeleting executable..."
		@rm -f $(NAME)
		@make clean -sC $(LIBFT_PATH)
		@echo "\033[1;32mDone\033[0m\n"

re: fclean all

.PHONY: all clean fclean re