# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Unknown <Unknown@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/19 16:55:45 by Unknown           #+#    #+#              #
#    Updated: 2015/02/19 23:02:11 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

H_DIR = h
C_DIR = srcs
O_DIR = o

LIBFT = libft/

FLAGS = -Wall -Wextra -Werror -O2
LINKS = -I$(H_DIR) -I$(LIBFT) -L$(LIBFT) -lft -ltermcap
DEBUG = 0

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

all:
	@if [ "$(DEBUG)" -eq "1" ]; then \
		make -C $(LIBFT) debug; \
		make -j4 _debug $(NAME); else \
		make -C $(LIBFT); \
		make -j4 $(NAME); fi

$(NAME): $(O_FILES)
	@gcc $(FLAGS) -o $@ $^ $(LINKS) && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\n" "$@"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(LINKS) -o $@ -c $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

debug: _debug all

clean: _clean
	@make -C $(LIBFT) clean

fclean: _fclean
	@make -C $(LIBFT) fclean

re: fclean all

rebug: fclean debug

_clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

_fclean: _clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

_re: _fclean all

_rebug: _fclean debug

_debug:
	$(eval FLAGS = -Wall -Wextra -g -D DEBUG_MODE)
	$(eval DEBUG = 1)

.PHONY: all debug clean fclean re rebug _clean _fclean _re _rebug _debug
