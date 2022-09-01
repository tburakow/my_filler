# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 12:15:46 by tburakow          #+#    #+#              #
#    Updated: 2022/09/01 12:07:15 by tburakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tburakow.filler

FUNCTIONS = main print_outs get_map get_player sub_error_output \
get_heat get_piece play adjust_to_map

FILES = $(patsubst %, %.c, $(FUNCTIONS))

OBJECTS = $(patsubst %, %.o, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	make -C ft_printf/
	gcc -Wall -Wextra -Werror -I. -L ft_printf/ -l ftprintf -g $(FILES) -o $(NAME)
#ar rcs $(NAME) $(OBJS) $(OBJECTS) $(PROBJS)

clean:
	rm -f $(OBJECTS)
	make -C ft_printf/ clean

fclean: clean
	rm -rf $(NAME)

	make -C ft_printf/ fclean

re: fclean all
