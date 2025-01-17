NAME = push_swap

DIR_LIBFT 	= ./lib/libft
DIR_SRC		= ./src
#DIR_SRC_BONUS	= ./src_bonus
DIR_OBJ		= $(DIR_SRC)/objects
#DIR_OBJ_BONUS	= $(DIR_SRC_BONUS)/objects_bonus
DIR_INC		= ./includes
HEADERS		= $(DIR_INC)/push_swap.h
#HEADERS_BONUS	= $(DIR_INC)/pipex_bonus.h

SOURCES = main.c \
	  arg_validate.c \
	  parse_input.c  \
	  exit_push_swap.c \
	  stack_manipulate.c \

#SOURCES_BONUS = pipex_main_bonus.c \
				pipex_bonus.c \
					       	pipex_init_bonus.c \
								pipex_cmd_bonus.c \
										pipex_exit_bonus.c \

OBJECTS		= $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
#OBJECTS_BONUS 	= $(addprefix $(DIR_OBJ_BONUS)/,$(SOURCES_BONUS:.c=.o))

LIBFT_FLAGS	= -L $(DIR_LIBFT) -lft

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -rf

all: libft $(NAME)
#bonus: libft .bonus

libft:
	@make -C $(DIR_LIBFT)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT_FLAGS) -o $@

#bonus: $(OBJECTS_BONUS)
#	$(CC) $(OBJECTS_BONUS) $(LIBFT_FLAGS) -o $(NAME)_bonus
#	@touch .bonus

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS) | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@

#$(DIR_OBJ_BONUS)/%.o: $(DIR_SRC_BONUS)/%.c $(HEADERS_BONUS) | $(DIR_OBJ_BONUS)
#	@$(CC) $(CFLAGS) -I$(DIR_INC) -c $< -o $@

$(DIR_OBJ):
		@mkdir -p $(DIR_OBJ)

#$(DIR_OBJ_BONUS):
#		@mkdir -p $(DIR_OBJ_BONUS)

clean:
	@$(RM) $(DIR_OBJ)
	@make -C $(DIR_LIBFT) clean
#	@$(RM) $(DIR_OBJ_BONUS)


fclean: clean
	@$(RM) $(NAME)
	@make -C $(DIR_LIBFT) fclean
#	$(RM) .bonus
#	@$(RM) $(NAME)_bonus



re: fclean all

.PHONY: all libft clean fclean re #bonus
