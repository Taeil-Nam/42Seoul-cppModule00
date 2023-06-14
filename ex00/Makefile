# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 14:57:14 by tnam              #+#    #+#              #
#    Updated: 2023/06/14 14:15:45 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	megaphone

CC				=	c++
CFLAG			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

SRCS			=	megaphone.cpp		\
					
OBJS			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all clean fclean re
