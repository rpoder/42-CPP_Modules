# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 21:14:29 by ronanpoder        #+#    #+#              #
#    Updated: 2023/02/16 13:09:31 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	sed_is_for_losers

SRC			=	main.cpp \

OBJS_PATH	=	./obj/

OBJS		=	$(addprefix $(OBJS_PATH), $(SRC:.cpp=.o))

DEPS		=	$(OBJS:.o=.d)

COMPILE		=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

EXEC		=	$(NAME)

all: $(NAME)

$(NAME):		$(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(EXEC)

re:	fclean all

$(OBJS_PATH)%.o : %.cpp
	mkdir -p $(dir $@)
	${COMPILE} ${FLAGS} -c $< -o $@ -MMD

-include $(DEPS)

.PHONY:	all clean fclean re
