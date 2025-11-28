NAME = minishell

CFILES = src/**/*.c

OBJS := $(CFILES:.c=.o)

CC = cc

LIBFTDIR = libft/

LIBFT := ${LIBFTDIR}libft.a

CFLAGS = -Wall -Wextra -Werror -ffast-math -ggdb3

LFLAGS := -I${LIBFTDIR} -lmath

all: ${NAME}

${NAME}:  ${OBJS} ${LIBFT}
	${CC} ${OBJS} ${LIBFT} ${LFLAGS} -o ${NAME}

%.o: %.c minishell.h
	${CC} -c ${CFLAGS} $< -o $@

${LIBFT}:
	cd ${LIBFTDIR} && make bonus

clean:
	cd ${LIBFTDIR} && make clean
	rm -f ${OBJS}

fclean: clean
	cd ${LIBFTDIR} && make fclean
	rm -f ${NAME}

re: fclean all

.PHONY: fclean clean all re bonus
