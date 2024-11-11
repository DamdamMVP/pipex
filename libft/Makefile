# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:53:09 by dalebran          #+#    #+#              #
#    Updated: 2024/11/06 00:50:24 by dalebran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

COLOR_DEFAULT = \033[39m\033[49m
COLOR_COMP = \033[92m
COLOR_REMOVE = \033[91m
COLOR_CREATED = \033[94m

# Files for each folder without .c extension
SRC_FD = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
			print_map read_map free_map calc_row_map copy_map
SRC_GNL = ft_get_next_line
SRC_IS = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint isdotorslash \
			isfullspace
SRC_STR = ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
			ft_strnstr ft_strncmp ft_substr ft_strjoin ft_strtrim \
			ft_split ft_strmapi ft_striteri ft_strdup ft_strcmp \
			clean_join
SRC_MEM = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr \
			ft_memcmp ft_calloc
SRC_TO = ft_atoi ft_atol ft_toupper ft_tolower ft_itoa ft_tobase16 ft_utoa
SRC_LST = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
			ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
			ft_lstmap free_node
SRC_PRINTF = ft_printf ft_handle_s ft_handle_c ft_handle_p ft_handle_d \
			ft_handle_i ft_handle_u ft_handle_x ft_handle_xcaps \
			ft_handle_percent
SRC_ERROR = ft_error ft_e_handle_s ft_e_handle_c ft_e_handle_p ft_e_handle_d \
			ft_e_handle_i ft_e_handle_u ft_e_handle_x ft_e_handle_xcaps \
			ft_e_handle_percent

# Adding the .c extension back to the file names
SRC_FD := $(addsuffix .c, $(SRC_FD))
SRC_GNL := $(addsuffix .c, $(SRC_GNL))
SRC_IS := $(addsuffix .c, $(SRC_IS))
SRC_STR := $(addsuffix .c, $(SRC_STR))
SRC_MEM := $(addsuffix .c, $(SRC_MEM))
SRC_TO := $(addsuffix .c, $(SRC_TO))
SRC_LST := $(addsuffix .c, $(SRC_LST))
SRC_PRINTF := $(addsuffix .c, $(SRC_PRINTF))
SRC_ERROR := $(addsuffix .c, $(SRC_ERROR))

# Prefixing folder name to each file
SRCS_FD = $(addprefix $(SRC_DIR)/ft_fd/, $(SRC_FD))
SRCS_GNL = $(addprefix $(SRC_DIR)/ft_gnl/, $(SRC_GNL))
SRCS_IS = $(addprefix $(SRC_DIR)/ft_is/, $(SRC_IS))
SRCS_STR = $(addprefix $(SRC_DIR)/ft_str/, $(SRC_STR))
SRCS_MEM = $(addprefix $(SRC_DIR)/ft_mem/, $(SRC_MEM))
SRCS_TO = $(addprefix $(SRC_DIR)/ft_to/, $(SRC_TO))
SRCS_LST = $(addprefix $(SRC_DIR)/ft_lst/, $(SRC_LST))
SRCS_PRINTF = $(addprefix $(SRC_DIR)/ft_printf/, $(SRC_PRINTF))
SRCS_ERROR = $(addprefix $(SRC_DIR)/ft_error/, $(SRC_ERROR))

# Merging all source files
SRCS = $(SRCS_FD) $(SRCS_IS) $(SRCS_STR) $(SRCS_MEM) $(SRCS_TO) $(SRCS_GNL) $(SRCS_LST) $(SRCS_PRINTF) $(SRCS_ERROR)
OBJS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))

all: $(NAME)
	@echo "$(COLOR_CREATED)$(NAME) created$(COLOR_DEFAULT)"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(COLOR_COMP)	-> Compilation of $<..."
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
