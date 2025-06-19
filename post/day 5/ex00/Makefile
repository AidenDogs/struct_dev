# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
NAME    = library

# Source files
SRCS    =	main.c catalog.c search.c ui.c getnextline/get_next_line.c getnextline/get_next_line_utils.c \
			getnextline/ft_printf.c getnextline/ft_print_memory_address.c getnextline/ft_conversions.c  \
			getnextline/ft_putnbr_unsigned_fd.c getnextline/ft_to_hex.c

# Object files
OBJS    = $(SRCS:.c=.o)

# Header dependencies
DEPS    = book.h catalog.h search.h ui.h getnextline/get_next_line.h getnextline/ft_printf.h

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Default target
all: $(LIBFT) $(NAME)

# Build your program, linking libft
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile your object files
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Build libft static library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean your project object files
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

# Full clean including binary and libft build files
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
