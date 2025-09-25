CC				= cc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -rf
NAME 			= push_swap
OBJ_DIR			= object
OBJ_DIR_BONUS	= object_bonus
SRCS_DIR		= Mandatory
BONUS_DIR		= Bonus
BONUS_NAME		= checker

SRCS			= $(SRCS_DIR)/main.c $(SRCS_DIR)/func_1.c $(SRCS_DIR)/func_4.c $(SRCS_DIR)/func_2.c $(SRCS_DIR)/func_3.c $(SRCS_DIR)/push_stack.c\
                  $(SRCS_DIR)/index_func.c $(SRCS_DIR)/lnkdlst_func.c $(SRCS_DIR)/parsing_func.c $(SRCS_DIR)/push_func.c $(SRCS_DIR)/rotate_func.c\
				  $(SRCS_DIR)/rrotate_func.c $(SRCS_DIR)/sorting_func.c $(SRCS_DIR)/sorting_func1.c $(SRCS_DIR)/swap_func.c $(SRCS_DIR)/func_error.c

SRCS_BONUS		= $(BONUS_DIR)/main_bonus.c $(BONUS_DIR)/func_1_bonus.c $(BONUS_DIR)/func_4_bonus.c $(BONUS_DIR)/func_2_bonus.c $(BONUS_DIR)/func_3_bonus.c $(BONUS_DIR)/gnl_utils_bonus.c\
                   $(BONUS_DIR)/lnkdlst_func_bonus.c $(BONUS_DIR)/parsing_func_bonus.c $(BONUS_DIR)/push_func_bonus.c $(BONUS_DIR)/rotate_func_bonus.c\
				  $(BONUS_DIR)/rrotate_func_bonus.c $(BONUS_DIR)/sorting_func_bonus.c $(BONUS_DIR)/gnl_bonus.c $(BONUS_DIR)/swap_func_bonus.c $(BONUS_DIR)/func_error_bonus.c

OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS 		= $(SRCS_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR_BONUS)/%.o)


all: $(OBJ_DIR) $(NAME)

bonus: $(OBJ_DIR_BONUS) $(BONUS_NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BONUS_NAME): $(OBJS_BONUS)
		$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/checker_bonus.h
		$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(SRCS_DIR)/push_swap.h
		$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
		@mkdir $@

$(OBJ_DIR_BONUS):
		@mkdir $@

clean:
		$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re:	fclean all
