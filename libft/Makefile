NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SOURCES = \
ft_atof.c\
ft_atoi.c\
ft_atoll.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strcmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_str_digit.c\
ft_free.c\
ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstsize_bonus.c\
ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c\
ft_lstclear_bonus.c\
ft_lstiter_bonus.c\
ft_lstmap_bonus.c\
ft_printf_putchar.c\
ft_printf_putstr.c\
ft_printf_putnbr.c\
ft_printf_puthex.c\
ft_printf_unsignbr.c\
ft_printf_putptr.c\
get_next_line.c\
get_next_line_utils.c

OBJ = $(SOURCES:%.c=$(OBJ_DIR)%.o)
OBJ_DIR = obj/

all: $(NAME)

$(OBJ_DIR):
	mkdir obj

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re
