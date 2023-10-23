# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2023/10/22 20:22:29 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
HELPERFUNC = helperfunc.a

SRCS =   main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
HELPERFUNCDIR = ./helperfunc


all: $(NAME)

makehelperfunc:
	make -C $(HELPERFUNCDIR)
	cp $(HELPERFUNCDIR)/$(HELPERFUNC) .
	mv $(HELPERFUNC) $(NAME)

$(NAME):helperfunc $(OBJS)
	$(AR) rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	cd $(HELPERFUNCDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(HELPERFUNCDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re bonus