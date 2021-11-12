NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = ./server.c \
				./minitalk_utils.c

SRCS_CLIENT = ./client.c \
				./minitalk_utils.c \

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c
	$(CC)  $(CFLAGS) -c $<
$(NAME_SERVER) : $(OBJS_SERVER)
	$(CC) -o $(NAME_SERVER) $^

$(NAME_CLIENT) : $(OBJS_CLIENT)
	$(CC) -o $(NAME_CLIENT) $^

clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)

re: clean all

.PHONY: all clean fclean re