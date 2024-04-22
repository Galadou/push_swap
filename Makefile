INCLUDE		= push_swap.h
NAME		= push_swap
COMP		= gcc
CFLAGS		= -Wall -Werror -Wextra -I./libft -g

SRC			= main.c\
			lst_function.c\
			set_list.c\
			set_id.c\
			check_arg.c\
			argv_to_tab.c\
			ft_atoi.c\
			free_tab_list.c\
			lst_swap_push.c\
			lst_rotate_and_reverse.c\
			butterflies.c\
			algorythm.c\
			algo_sort_small.c\
			check_sort.c


OBJS=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		echo $(OBJS)
		@make bonus --directory ./libft
		@$(COMP) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
		@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
		fi

%.o : %.c
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		make clean --directory ./libft

fclean: clean
		rm -f $(NAME)
		make fclean --directory ./libft

re: fclean $(NAME)

.PHONY: clean fclean re all
