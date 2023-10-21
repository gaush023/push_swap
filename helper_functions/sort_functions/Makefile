# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 00:17:25 by sagemura          #+#    #+#              #
#    Updated: 2023/10/21 17:51:11 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sort_function.a
SRCS =  execute_sort.c helper_sort.c is_sorted_stack_a.c magic_sort_3.c operation.c operation_2.c operation_3.c situation_three.c situation_three_type_a.c situation_three_type_b.c situation_two.c sort_bigstacks.c

OBJS = $(SRCS:.c=.o)
ALL_OBJS = $(OBJS)

ifdef ADD 
    ALL_OBJS += $(BONUS_SRCS:.c=.o)
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) ADD=1 $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus