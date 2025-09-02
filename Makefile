NAME = philosophers
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   utils.c \
	   check_args.c \
	   init_data.c \
	   philo_routine.c \
	   threads.c \
	   overseer.c

OBJS = $(SRCS:.c=.o)

all:
	@echo "\033[1;93m [WAIT] \033[0m\t\033[1;35mBuilding Philosophers...\033[0m"
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m [OK]   \033[0m\t\033[1;35mPhilosophers built successfully!\033[0m"

%.o: %.c
	@echo "\033[1;90m [COMPILE] \033[0m $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[1;34m [CLEAN] \033[0m Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m [FCLEAN] \033[0m Executable and object files removed."

re: fclean all

.PHONY: all clean fclean re