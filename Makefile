# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilib/libft -Wunreachable-code -Ofast -g

# MLX42 Paths
LIBMLX = ./lib/MLX42
MLX_BUILD = $(LIBMLX)/build

# Headers and Libraries
HEADERS = -I./include -I$(LIBMLX)/include
LIBS = $(MLX_BUILD)/libmlx42.a -ldl -lglfw -pthread -lm

# Source and Object Files
SRC_DIR = src
LIBFT_DIR = lib/libft

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/mlx_init.c \
	$(SRC_DIR)/mlx_controls.c \
	$(SRC_DIR)/parse_input.c \
	$(SRC_DIR)/fractal.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/fractal_mandelbrot.c \
	$(SRC_DIR)/fractal_julia.c \
	$(SRC_DIR)/fractal_burning_ship.c \
	$(SRC_DIR)/fractal_color.c

OBJS = $(SRCS:.c=.o)

# Targets
NAME = fractal
LIBFT = $(LIBFT_DIR)/libft.a

# Quiet Mode
ifneq ($(SHOW),1)
QUIET = @
endif

# Main Rule
all: submodules libmlx $(LIBFT) $(NAME)

# --- Submodule Initialization ---
.PHONY: submodules
submodules:
	@if [ ! -d "$(LIBMLX)/.git" ]; then \
		echo "Initializing submodules..."; \
		git submodule update --init --recursive; \
	fi

# --- MLX42 Build ---
.PHONY: libmlx
libmlx: submodules
	@if [ ! -f "$(MLX_BUILD)/libmlx42.a" ]; then \
		echo "Building MLX42..."; \
		cmake $(LIBMLX) -B $(MLX_BUILD) && make -C $(MLX_BUILD) -j4; \
	fi

# --- Libft Build ---
$(LIBFT):
	$(QUIET)make -C $(LIBFT_DIR)

# --- Fractal Executable ---
$(NAME): $(OBJS) $(LIBFT) libmlx
	$(QUIET)$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

# --- Object Files ---
%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling $(notdir $<)\n"

# --- Clean Rules ---
clean:
	$(QUIET)rm -f $(OBJS)
	$(QUIET)make -C $(LIBFT_DIR) clean
	@rm -rf $(MLX_BUILD)

fclean: clean
	$(QUIET)rm -f $(NAME)
	$(QUIET)make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean re fclean libmlx submodules