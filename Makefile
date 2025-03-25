CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilib/libft -Wunreachable-code -Ofast -g

LIBMLX = ./lib/MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR = src
LIBFT_DIR = lib/libft

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/mlx_init.c \
	$(SRC_DIR)/parse_input.c \
	$(SRC_DIR)/fractal.c \
	$(SRC_DIR)/utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

NAME = fractal

ifneq ($(SHOW),1)
QUIET = @
endif

all: libmlx $(LIBFT) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	$(QUIET)make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) libmlx
	$(QUIET)$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling $(notdir $<)\n"

clean:
	$(QUIET)rm -f $(OBJS)
	$(QUIET)make -C $(LIBFT_DIR) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	$(QUIET)rm -f $(NAME)
	$(QUIET)make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean re fclean libmlx
