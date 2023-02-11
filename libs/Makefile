
NAME		= 	libs.a
CFLAGS		= 	-Wall -Werror -Wextra
CC			= 	cc
RM			=	rm -f
AR			=	ar -crs

LIBFT		:=	libft
PRINTF 		:=	ft_printf
GNL			:=	get_next_line

# LIBFT
LIBFTCFILES	:=	ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_calloc2.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
				ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin_compact.c
LIBFTCFILES	:=	$(addprefix $(LIBFT)/, $(LIBFTCFILES))

# PRINTF
PRINTFCFILES :=	ft_printf.c printf_hex.c printf_tools.c
PRINTFCFILES :=	$(addprefix $(PRINTF)/, $(PRINTFCFILES))

# GNL
GNLCFILES	:=	get_next_line.c get_next_line_utils.c
GNLCFILES	:=	$(addprefix $(GNL)/, $(GNLCFILES))

# LIBS
CFILES		:=	$(LIBFTCFILES) $(PRINTFCFILES) $(GNLCFILES)
OFILES		:=	$(CFILES:.c=.o)

GREEN		= 	\033[0;32m
BLUE		=	\033[0;34m
WHITE		=	\033[0m


# RULES

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)
	@echo "$(GREEN)*** Libs compiled!***$(WHITE)"

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OFILES)
	@echo "$(BLUE)*** Object files libs cleaned! ***$(WHITE)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE)*** Executable (.a) file libs cleaned! ***$(WHITE)"

re: fclean all
	@echo "$(GREEN)*** Cleaned and rebuilt libs! ***$(WHITE)"

all: $(NAME)

.PHONY:  test clean fclean re all

