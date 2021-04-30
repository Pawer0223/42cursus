NAME = libasm.a

NA = nasm

NFLAGS = -f macho64

CC  = arch -x86_64 gcc

SRC = ft_read.s \
	ft_write.s \
	ft_strcmp.s \
	ft_strlen.s \
	ft_strcpy.s \
	ft_strdup.s \

B_SRC = ft_list_size_bonus.s \
	ft_list_push_front_bonus.s \
	ft_list_sort_bonus.s \

OBJ = $(SRC:.s=.o)

B_OBJ = $(SRC:.s=.o) $(B_SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33mUpdating library..."
	ar rc $(NAME) $(OBJ)
	@echo "\033[0m"

%.o: %.s
	@echo "\033[0;32mGenerating binary..."
	$(NA) $(NFLAGS) $<
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	rm -f $(B_OBJ)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving library..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

bonus: $(B_OBJ)
	@echo "\033[0;33mUpdating library (with bonuses)..."
	ar rc $(NAME) $(B_OBJ)
	@echo "\033[0m"

.PHONY: all re clean fclean bonus
