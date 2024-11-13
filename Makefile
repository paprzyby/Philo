# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 15:59:16 by paprzyby          #+#    #+#              #
#    Updated: 2024/11/13 15:51:28 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_GREEN	=	\033[0;32m
COLOUR_END		=	\033[0m

NAME			=	philo

SOURCE			=	main.c \
					source/cleanup.c \
					source/struct_init.c \
					utils/ft_putstr_fd.c \
					utils/ft_isdigit.c \
					utils/ft_atol.c \
					source/creating_threads.c \
					source/philo_function.c \
					source/checker_function.c \
					source/get_timestamp.c

OBJECTS			=	$(SOURCE:.c=.o)

CC				=	cc

RM				=	rm -rf

FLAGS			=	-Wall -Wextra -Werror

$(NAME):	$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) built successfully!$(COLOUR_END)"

%.o:			%.c philo.h
				$(CC) $(FLAGS) -c $< -o $@

all:			$(NAME)

clean:
	$(RM) $(OBJECTS)
	@echo "$(COLOUR_GREEN)objects removed successfully..$(COLOUR_END)"

fclean:	clean
	$(RM) $(NAME) $(OBJECTS)
	@echo "$(COLOUR_GREEN)$(NAME) cleaned successfully..$(COLOUR_END)"

re:				fclean all

.PHONY:			all clean fclean re
