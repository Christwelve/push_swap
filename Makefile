
PUSH_SWAP	= 	push_swap
CHECKER		=	checker
CFLAGS		= 	-Wall -Werror -Wextra
CC			= 	cc
RM			=	rm -rf
INCLUDE 	= 	-I include

MAN_FILES	=	src_man/main.c src_man/circle.c src_man/utils_parse.c src_man/utils_algorithm.c src_man/algorithms.c\
				src_man/operations/push.c src_man/operations/swap.c src_man/operations/rotate.c src_man/operations/reverse_rotate.c
BONUS_FILES	=	src_bonus/checker.c src_bonus/circle.c src_bonus/utils_parse.c src_bonus/utils_algorithm.c src_bonus/utils_checker.c\
				src_bonus/operations/push.c src_bonus/operations/swap.c src_bonus/operations/rotate.c src_bonus/operations/reverse_rotate.c				

MAN_OBJ		=	$(MAN_FILES:.c=.o)
BONUS_OBJ	=	$(BONUS_FILES:.c=.o)

LIBS		=	libs/libs.a

GREEN		= 	\033[0;32m
BLUE		=	\033[0;94m
WHITE		=	\033[0m


ifdef DEBUG
	CFLAGS += -g
endif

# RULES

all: $(PUSH_SWAP) 

$(PUSH_SWAP): $(LIBS) $(MAN_OBJ)
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(MAN_OBJ) $(LIBS) $(INCLUDE)
	@echo "$(GREEN)*** Push_swap compiled!***$(WHITE)"

$(CHECKER): $(LIBS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJ) $(LIBS) $(INCLUDE)
	@echo "$(GREEN)*** Checker compiled!***$(WHITE)"	

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
	@if [ ! -d "./libs" ]; then git clone https://github.com/Christwelve/libs.git; fi
	@make --silent DEBUG=$(DEBUG) -C libs

bonus: $(CHECKER)

clean:
	$(RM) $(MAN_OBJ)
	$(RM) $(BONUS_OBJ)
	make clean --silent -C libs
	@echo "$(BLUE)*** Object files push_swap and checker cleaned! ***$(WHITE)"

fclean: clean
	$(RM) $(PUSH_SWAP)
	$(RM) $(CHECKER)
	make fclean --silent -C libs
	@echo "$(BLUE)*** Executable push_swap and checker cleaned! ***$(WHITE)"

re: fclean all
	@echo "$(GREEN)*** Cleaned and rebuilt push_swap! ***$(WHITE)"

.PHONY:  bonus fclean re all