# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 22:21:38 by tnam              #+#    #+#              #
#    Updated: 2023/06/14 16:27:41 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	account

CC				=	c++
CFLAG			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

INCLUDES		=	./

SRCS			=	Account.cpp			\
					tests.cpp			\
					
OBJS			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAG) -I $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all clean fclean re
