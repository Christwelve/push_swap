
NAME		= 	push_swap
CFLAGS		= 	-Wall -Werror -Wextra
CC			= 	cc
RM			=	rm -rf
INCLUDE 	= 	-I include

MAN_FILES	=	src/main.c src/circle.c src/utils_parse.c src/utils_algorithm.c \
				src/push.c src/swap.c src/rotate.c src/reverse_rotate.c \

MAN_OBJ		=	$(MAN_FILES:.c=.o)

LIBS		=	libs/libs.a

GREEN		= 	\033[0;32m
BLUE		=	\033[0;94m
WHITE		=	\033[0m


ifdef DEBUG
	CFLAGS += -g
endif

# RULES

all: $(NAME)

$(NAME): $(LIBS) $(MAN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MAN_OBJ) $(LIBS) $(INCLUDE)
	@echo "$(GREEN)*** push_swap compiled!***$(WHITE)"

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
	@if [ ! -d "./libs" ]; then git clone https://github.com/Christwelve/libs.git; fi
	@make --silent DEBUG=$(DEBUG) -C libs

clean:
	$(RM) $(MAN_OBJ)
	make clean --silent -C libs
	@echo "$(BLUE)*** Object files push_swap cleaned! ***$(WHITE)"

fclean: clean
	$(RM) $(NAME)
	make fclean --silent -C libs
	@echo "$(BLUE)*** Executable (.a) file push_swap cleaned! ***$(WHITE)"

re: fclean all
	@echo "$(GREEN)*** Cleaned and rebuilt push_swap! ***$(WHITE)"

.PHONY:  test clean fclean re all