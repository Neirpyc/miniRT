CC = clang
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux
LD = ld
MAKE = make
RM = rm -rf
AFLAGS = -lXext -lX11 -lm -lpthread
BUILDFLAGS = -mllvm -polly
OPTIMIZATION = -O3 -fno-stack-protector \
-fno-math-errno -funsafe-math-optimizations -fassociative-math -freciprocal-math \
-funroll-loops -ftree-vectorize -finline-functions -ffp-contract=fast
NAME = miniRT
SRC =	srcs/lists/list_size.c \
        srcs/lists/list_new.c \
        srcs/lists/list_clear.c \
        srcs/lists/list_push_front.c \
        srcs/lists/list_pop.c \
        srcs/window/window.c \
        srcs/window/redraw.c \
        srcs/window/filters/blue.c \
        srcs/window/filters/green.c \
        srcs/window/filters/red.c \
        srcs/window/filters/filters.c \
        srcs/window/draw.c \
        srcs/libft/ft_isspace.c \
        srcs/libft/ft_putnbr_fd.c \
        srcs/libft/ft_memcpy.c \
        srcs/libft/ft_strcmp.c \
        srcs/libft/ft_toupper.c \
        srcs/libft/ft_memcmp.c \
        srcs/libft/ft_isdigit.c \
        srcs/libft/ft_memset.c \
        srcs/libft/ft_strlen.c \
        srcs/fd_until/get_state.c \
        srcs/fd_until/fd_close_until.c \
        srcs/fd_until/t_list.c \
        srcs/fd_until/state_pop.c \
        srcs/fd_until/t_slice.c \
        srcs/fd_until/fd_read_until.c \
        srcs/scene/scene.c \
        srcs/main.c \
        srcs/errors/errors.c \
        srcs/bmp/open_image.c \
        srcs/bmp/bmp.c \
        srcs/parse/parse.c \
        srcs/parse/validate_scene.c \
        srcs/parse/args/args.c \
        srcs/parse/args/arg_error.c \
        srcs/parse/type/light.c \
        srcs/parse/type/ambient.c \
        srcs/parse/type/sphere.c \
        srcs/parse/type/plane.c \
        srcs/parse/type/resolution.c \
        srcs/parse/type/triangle.c \
        srcs/parse/type/p_light.c \
        srcs/parse/type/material.c \
        srcs/parse/type/cylinder.c \
        srcs/parse/type/camera.c \
        srcs/parse/type/cone.c \
        srcs/parse/type/filter.c \
        srcs/parse/type/cube.c \
        srcs/parse/type/pyramid.c \
        srcs/parse/type/squares.c \
        srcs/parse/link_materials.c \
        srcs/parse/compounds/compound_cone.c \
        srcs/parse/compounds/compound_cylinder.c \
        srcs/parse/compounds/compound_cube.c \
        srcs/parse/compounds/expand_compounds.c \
        srcs/parse/compounds/compound_pyramid.c \
        srcs/parse/link_materials1.c \
        srcs/parse/list_to_array_utils.c \
        srcs/parse/conf_err.c \
        srcs/parse/list_to_array.c \
        srcs/parse/parse_line.c \
        srcs/parse/fmt_bonus.c \
        srcs/parse/link_materials0.c \
        srcs/parse/conversions/parse_float_01.c \
        srcs/parse/conversions/parse_filter.c \
        srcs/parse/conversions/parse_position.c \
        srcs/parse/conversions/parse_disruption.c \
        srcs/parse/conversions/parse_rgb.c \
        srcs/parse/conversions/parse_p_double.c \
        srcs/parse/conversions/ft_strtod.c \
        srcs/parse/conversions/parse_float_1inf.c \
        srcs/parse/conversions/ft_strtoll.c \
        srcs/parse/conversions/parse_180_dbl.c \
        srcs/parse/conversions/parse_endl.c \
        srcs/parse/conversions/parse_rotation.c \
        srcs/parse/conversions/parse_float_0exinf.c \
        srcs/parse/conversions/parse_angle.c \
        srcs/parse/conversions/parse_p_int.c \
        srcs/raytrace/ambient.c \
        srcs/raytrace/bounding_box.c \
        srcs/raytrace/objetcs/spheres/bounding_box.c \
        srcs/raytrace/objetcs/spheres/intersect.c \
        srcs/raytrace/objetcs/spheres/move.c \
        srcs/raytrace/objetcs/spheres/get_material.c \
        srcs/raytrace/objetcs/spheres/normal.c \
        srcs/raytrace/objetcs/spheres/get_t.c \
        srcs/raytrace/objetcs/spheres/get_funcs.c \
        srcs/raytrace/objetcs/planes/bounding_box.c \
        srcs/raytrace/objetcs/planes/intersect.c \
        srcs/raytrace/objetcs/planes/move.c \
        srcs/raytrace/objetcs/planes/get_material.c \
        srcs/raytrace/objetcs/planes/normal.c \
        srcs/raytrace/objetcs/planes/get_t.c \
        srcs/raytrace/objetcs/planes/get_funcs.c \
        srcs/raytrace/objetcs/squares/bounding_box.c \
        srcs/raytrace/objetcs/squares/intersect.c \
        srcs/raytrace/objetcs/squares/move.c \
        srcs/raytrace/objetcs/squares/get_material.c \
        srcs/raytrace/objetcs/squares/normal.c \
        srcs/raytrace/objetcs/squares/get_t.c \
        srcs/raytrace/objetcs/squares/get_funcs.c \
        srcs/raytrace/objetcs/cone/bounding_box.c \
        srcs/raytrace/objetcs/cone/intersect.c \
        srcs/raytrace/objetcs/cone/move.c \
        srcs/raytrace/objetcs/cone/get_material.c \
        srcs/raytrace/objetcs/cone/normal.c \
        srcs/raytrace/objetcs/cone/get_t.c \
        srcs/raytrace/objetcs/cone/get_funcs.c \
        srcs/raytrace/objetcs/cylinder/bounding_box.c \
        srcs/raytrace/objetcs/cylinder/intersect.c \
        srcs/raytrace/objetcs/cylinder/move.c \
        srcs/raytrace/objetcs/cylinder/get_material.c \
        srcs/raytrace/objetcs/cylinder/normal.c \
        srcs/raytrace/objetcs/cylinder/get_t.c \
        srcs/raytrace/objetcs/cylinder/get_funcs.c \
        srcs/raytrace/objetcs/triangles/bounding_box.c \
        srcs/raytrace/objetcs/triangles/intersect.c \
        srcs/raytrace/objetcs/triangles/move.c \
        srcs/raytrace/objetcs/triangles/get_material.c \
        srcs/raytrace/objetcs/triangles/normal.c \
        srcs/raytrace/objetcs/triangles/get_t.c \
        srcs/raytrace/objetcs/triangles/get_funcs.c \
        srcs/raytrace/objetcs/disc/intersect.c \
        srcs/raytrace/objetcs/disc/move.c \
        srcs/raytrace/objetcs/disc/get_material.c \
        srcs/raytrace/objetcs/disc/normal.c \
        srcs/raytrace/objetcs/disc/get_t.c \
        srcs/raytrace/objetcs/disc/get_funcs.c \
        srcs/raytrace/objetcs/disc/bouding_box.c \
        srcs/raytrace/ray_utils.c \
        srcs/raytrace/disruptions/rainbow.c \
        srcs/raytrace/disruptions/checkerboard.c \
        srcs/raytrace/disruptions/sine.c \
        srcs/raytrace/disruptions/disruptions.c \
        srcs/raytrace/equation/fresnel.c \
        srcs/raytrace/equation/quadratic.c \
        srcs/raytrace/specular_lighting.c \
        srcs/raytrace/ray.c \
        srcs/raytrace/raytrace_pixel.c \
        srcs/raytrace/vec3/rotation.c \
        srcs/raytrace/vec3/scalar.c \
        srcs/raytrace/vec3/common_vecs.c \
        srcs/raytrace/vec3/norm.c \
        srcs/raytrace/vec3/common_eq.c \
        srcs/raytrace/vec3/scale.c \
        srcs/raytrace/vec3/cross.c \
        srcs/raytrace/vec3/sub.c \
        srcs/raytrace/vec3/add.c \
        srcs/raytrace/diffuse_lighting.c \
        srcs/render/movement/translate_1.c \
        srcs/render/movement/translate_0.c \
        srcs/render/movement/movement.c \
        srcs/render/movement/rotate_0.c \
        srcs/render/movement/rotate_1.c \
        srcs/render/start_threads.c \
        srcs/render/render.c \
        srcs/render/switch_cameras.c \
        srcs/render/stop_threads.c \
        srcs/render/switch_objetcs.c \
        srcs/render/switch_mode.c \
        srcs/gc_malloc/gc_open.c \
        srcs/gc_malloc/gc_rm_cb.c \
        srcs/gc_malloc/pool.c \
        srcs/gc_malloc/gc_exit.c \
        srcs/gc_malloc/gc_add_cb.c \
        srcs/gc_malloc/gc_free.c \
        srcs/gc_malloc/gc_close.c \
        srcs/gc_malloc/gc_malloc.c

OBJ = $(SRC:.c=.o)
SEMB = assets/errors.bin
EMB = $(SEMB:.bin=.o)
MLX = minilibx-linux/libmlx.a
TMP = tmp
PROFRT =	profile_default.rt profile_rev_n.rt profile_inside_sphere.rt profile_inside_cylinder.rt \
			profile_inside_cone.rt profile_small_r.rt profile_invisible.rt profile_aa.rt \
			profile_spec.rt profile_d_0.rt profile_d_1.rt profile_d_2.rt profile_lights.rt
ASS_PROFRT = $(addprefix assets/,$(PROFRT))
TMP_PROFRT = $(addprefix $(TMP)/,$(PROFRT))
PROFRAW = $(TMP_PROFRT:.rt=.profraw)
PROF = $(TMP)/miniRT.prof
PROFBIN = $(TMP)/miniRT_profiler

all: $(NAME)

$(NAME): $(OBJ) $(EMB) $(MLX)
	$(CC) $(CFLAGS)	$(OBJ) $(MLX) $(EMB) -o $(NAME) $(AFLAGS)

fast: $(SRC) $(EMB) $(MLX) $(PROF)
	$(CC) $(CFLAGS) $(OPTIMIZATION) -flto=thin -fprofile-instr-use=$(PROF)  \
	$(SRC) $(MLX) $(BUILDFLAGS) $(EMB) -o $(NAME) $(AFLAGS)

$(PROF): $(PROFRAW)
	llvm-profdata merge -output=$(PROF) $(PROFRAW)

$(PROFRAW): $(PROFBIN) $(TMP_PROFRT)
	$(foreach RT_FILE, $(PROFRT), $(call PROFILE_ONCE))
define PROFILE_ONCE
$(RM) $(TMP)/frame.bmp
cd $(TMP) && LLVM_PROFILE_FILE=$(RT_FILE:.rt=.profraw) ./miniRT_profiler $(RT_FILE) --save

endef

$(TMP_PROFRT): $(ASS_PROFRT)
	cp $(ASS_PROFRT) $(TMP)

$(PROFBIN): $(SRC) $(EMB) $(MLX) srcs/errors/errors.o $(TMP)
	$(CC) $(CFLAGS) $(OPTIMIZATION) -flto=thin -fprofile-instr-generate\
    $(SRC) $(MLX) $(EMB) $(BUILDFLAGS) -o $(PROFBIN) $(AFLAGS)

$(TMP):
	mkdir $(TMP)

slow: $(NAME)

clean: cleantmp
	$(RM) $(OBJ) $(EMB)
	cd minilibx-linux && $(MAKE) clean

cleantmp:
	$(RM) $(TMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

benchmark: $(TMP)/benchmark.rt $(TMP)/$(NAME)
	@$(RM) $(TMP)/frame.bmp
	@cd $(TMP) && time -p ./miniRT benchmark.rt --save

grademe: assets/grademe.sh
	@assets/grademe.sh

$(TMP)/benchmark.rt: $(TMP)
	@cp assets/benchmark.rt $(TMP)

$(TMP)/$(NAME): $(NAME)
	@cp $(NAME) $(TMP)

$(OBJ) : %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(EMB) : %.o: %.bin
	$(LD) -r -b binary $< -o $@

$(MLX) :
	cd minilibx-linux && $(MAKE)

.PHONY: all clean fclean re cleantmp slow fast benchmark grademe
