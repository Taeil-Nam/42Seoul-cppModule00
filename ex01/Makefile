# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 22:21:38 by tnam              #+#    #+#              #
#    Updated: 2023/06/13 22:21:38 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	phonebook

CC				=	c++
CFLAG			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

SRCS			=	phonebook.cpp		\
					
OBJS			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all clean fclean re
