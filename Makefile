# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 17:00:59 by edegarci          #+#    #+#              #
#    Updated: 2025/01/20 17:34:03 by edegarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
YELLOW		=	\033[0;33m
GREEN		=	\033[0;32m
NC			=	\033[0m

DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
MLX			=	-lXext -lX11 -lm -lbsd

# Executable name
NAME		=	so_long

# Files
SRC_FILES 	= main read_map validate_map validate_path utils init_game

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT		=	libs/libft
MINILIBX	= 	minilibx-linux

# Libraries 
LIBS		= $(MINILIBX)/libmlx.a $(MLX) $(LIBFT)/libft.a

# Directories
SRC_DIR = src/
OBJ_DIR = objs/

# RULES #
all:		minilibx libft $(NAME)

# Compile executable
$(NAME):$(OBJ)
		$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)

	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(GREEN)Compiled!$(NC)"

# Compile libft library
libft:
	@echo "$(YELLOW)COMPILING LIBFT...$(NC)"
	@$(MAKE) -C ./$(LIBFT)
	@echo "$(GREEN)LIBFT HAS BEEN COMPILED$(NC)"

# Compile minilibx library
minilibx:
	@echo "$(YELLOW)COMPILING MINILIBX...$(NC)"
	@$(MAKE) -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX HAS BEEN COMPILED$(NC)"

# Clean temporary minilibx files
fclean_mlx:
	@make fclean -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX FULL CLEANED!$(NC)"

# Clean temporary libft files
fclean_libft:
	@make fclean -C ./$(LIBFT)
	@echo "$(GREEN)LIBFT FULL CLEANED!$(NC)"

# Clean object files and directory
clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(GREEN)OBJS AND DIRECTORY CLEANED!$(NC)"

# Clean object files, directory, and executable
fclean: clean fclean_libft
	@$(RM) $(NAME)
	@echo "$(GREEN)EXECUTABLE CLEANED!$(NC)"

# Rebuild all
re: fclean all