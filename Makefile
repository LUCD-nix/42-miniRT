NAME = miniRT

CFILES := src/main.c \
	src/shapes/box.c \
	src/shapes/cylinder.c \
	src/shapes/plane.c \
	src/shapes/rectangle.c \
	src/shapes/sphere.c \
	src/vec3/length3.c \
	src/vec3/add3.c \
	src/vec3/diff3.c \
	src/vec3/dot3.c \
	src/vec3/fmult3.c \
	src/vec3/norm3.c

OBJS := $(CFILES:.c=.o)

CC = cc

LIBFTDIR = libft/
MLIBXDIR = minilibx-linux/

LIBFT := ${LIBFTDIR}libft.a
MLIBX := ${MLIBXDIR}libmlx.a ${MLIBXDIR}libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror -O3 -ggdb3 \
	-ffast-math \
	-funsafe-math-optimizations \
	-fno-math-errno \
	-fassociative-math

LFLAGS := -I${LIBFTDIR} -I${MLIBXDIR} -lXext -lX11 -lm

all: ${NAME}

${NAME}:  ${OBJS} ${LIBFT} ${MLIBX}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLIBX} ${MLIBX_OS} ${LFLAGS} -o ${NAME}

%.o: %.c minishell.h
	${CC} -c ${CFLAGS} $< -o $@

${LIBFT}:
	cd ${LIBFTDIR} && make bonus

${MLIBX}:
	cd ${MLIBXDIR} && ./configure

clean:
	cd ${LIBFTDIR} && make clean
	rm -f ${OBJS}

fclean: clean
	cd ${LIBFTDIR} && make fclean
	cd ${MLIBXDIR} && ./configure clean
	rm -f ${NAME}

re: fclean all

.PHONY: fclean clean all re bonus
