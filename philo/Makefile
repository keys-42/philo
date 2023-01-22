NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE		=	-I ./include/

SRCS		= 	srcs/main.c \
				srcs/reserve/checks.c \
				srcs/reserve/init.c \
				srcs/reserve/error.c \
				srcs/thread/philo/eat.c \
				srcs/thread/philo/fork.c \
				srcs/thread/philo/philo_utils.c \
				srcs/thread/philo/philo.c \
				srcs/thread/philo/sleep.c \
				srcs/thread/philo/think.c \
				srcs/thread/message.c \
				srcs/thread/monitor.c \
				srcs/thread/monitor_utils.c \
				srcs/utils/ft_atol.c \
				srcs/utils/ft_isdigit.c \
				srcs/utils/ft_isspace.c \
				srcs/utils/time.c

OBJDIR   = obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME):$(OBJS)
		$(CC) $^ $(CFLAGS) -o $@ -lpthread

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) -r $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re : fclean all

.PHONY:
		all clean fclean re
