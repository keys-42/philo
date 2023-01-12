NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror# -fsanitize=thread
# CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=leak
# CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
# CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=thread
# CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./include/

SRCS		= 	srcs/main.c \
				srcs/checks/checks.c \
				srcs/make/make_init.c \
				srcs/monitor/is_deth.c \
				srcs/monitor/monitor.c \
				srcs/philo/philo_action.c \
				srcs/philo/philo.c \
				srcs/print/error.c \
				srcs/print/action_message.c \
				srcs/utils/ft_atol.c \
				srcs/utils/ft_isdigit.c \
				srcs/utils/ft_isspace.c \
				srcs/time.c

OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME):$(OBJS)
		$(CC) $^ $(CFLAGS) -o $@ -lpthread
# $(CC) -pthread $^ $(CFLAGS) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<
# $(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $< -lpthread

clean:
		$(RM) -r $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re
