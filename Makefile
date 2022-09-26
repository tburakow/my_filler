# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 12:15:46 by tburakow          #+#    #+#              #
#    Updated: 2022/09/27 00:25:39 by tburakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tburakow.filler

CC := gcc

CFLAGS := -Wall -Werror -Wextra

FUNCTIONS = main get_map get_player sub_error_output \
get_heat get_piece play heat_extras hits_and_crashes \
parse_direction heat_checks_one free_s\
heat_checks_two

INCS := includes/

FILES = $(patsubst %, %.c, $(FUNCTIONS))

OBJECTS = $(patsubst %, %.o, $(FUNCTIONS))

all: $(NAME)

$(OBJECTS): %.o: %.c objects_msg
	@$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "\033[36mbuilding executable $@\033[0m"
	@make -C ft_printf/
	@$(CC) $(CFLAGS) -L ft_printf/ -l ftprintf $(OBJECTS) -o $(NAME)
	@echo "\033[92mdone.\033[0m"

clean:
	@echo "\033[90mcleaning objects...\033[0m"
	@rm -f $(OBJECTS)
	@make -C ft_printf/ clean

fclean: clean
	@echo "\033[39mcleaning all...\033[0m"
	@rm -rf $(NAME)
	@make -C ft_printf/ fclean

re: fclean all

.INTERMEDIATE: objects_msg
objects_msg:
	@echo "\033[34mbuilding objects...\033[0m"

.PHONY: all clean fclean re