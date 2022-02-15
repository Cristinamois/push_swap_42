# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmois <cmois@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 16:32:43 by cmois             #+#    #+#              #
#    Updated: 2021/12/31 10:38:49 by cmois            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap



SRCS	=	closing_file.c errors_in_arg.c give_value_of_index_to_lst.c \
			list_care.c main.c sorting_by_number_of_args.c sort_five.c swap.c \
			push.c rotate.c reverse_rotate.c radix_sort.c incognito_sorting.c \
			list_care_part_2.c errors_in_stack.c\
			
OBJS	=	${SRCS:.c=.o}


CC		=	cc
INCS	=	-I ./ -I ./libft/
CFLAGS	=	-Wall -Wextra -Werror -g

-include $(DEPS)
all:		${NAME}
${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${CFLAGS} ${INCS} $^ -o $@ ./libft/libft.a

%.o: %.c
			${CC} ${CFLAGS} ${INCS} -c $< -o $@


clean:
			${MAKE} -C libft clean
			${RM} ${OBJS}
			${RM} objets 

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
