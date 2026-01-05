NAME = miniRT

CFILES = src/main.c \
	src/lighting/add_light_to_obj.c \
	src/mat3/mat3mat3.c \
	src/mat3/mat3vec.c \
	src/mat3/rot_mat3.c \
	src/mat3/rot_mat3_int.c \
	src/mat3/transp3.c \
	src/rendering/apply_lights.c \
	src/rendering/camera_setup.c \
	src/rendering/fast_render.c \
	src/rendering/full_render.c \
	src/rendering/get_normal.c \
	src/rendering/get_uv.c \
	src/rendering/raymarch.c \
	src/rendering/scene.c \
	src/rendering/soft_shadow.c \
	src/shapes/box.c \
	src/shapes/combining.c \
	src/shapes/cylinder.c \
	src/shapes/plane.c \
	src/shapes/smooth_combining.c \
	src/shapes/sphere.c \
	src/vec2/abs2.c \
	src/vec2/add2.c \
	src/vec2/diff2.c \
	src/vec2/dot2.c \
	src/vec2/fmult2.c \
	src/vec2/length2.c \
	src/vec2/max2f.c \
	src/vec2/norm2.c \
	src/vec3/abs3.c \
	src/vec3/add3.c \
	src/vec3/diff3.c \
	src/vec3/dot3.c \
	src/vec3/fmult3.c \
	src/vec3/length3.c \
	src/vec3/max3f.c \
	src/vec3/norm3.c \
	src/vec3/trans_rot3.c \
	src/window/init_window.c

OBJS := $(CFILES:.c=.o)

CC = cc

LIBFTDIR = libft/
MLIBXDIR = minilibx-linux/

LIBFT := ${LIBFTDIR}libft.a
MLIBX := ${MLIBXDIR}libmlx.a ${MLIBXDIR}libmlx_Linux.a

CFLAGS = -std=gnu99 -O3 \
	-ffast-math \
	-funsafe-math-optimizations \
	-fno-math-errno \
	-fassociative-math

LFLAGS := -I${LIBFTDIR} -I${MLIBXDIR} -lXext -lX11 -lm

all: ${NAME}

run : ${NAME}
	./${NAME}

${NAME}:  ${OBJS} ${LIBFT} ${MLIBX}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLIBX} ${LFLAGS} -o ${NAME}

%.o: %.c
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

.PHONY: fclean clean all re bonus run
