NAME		=	pipex

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -I $(INCDIR) -I $(INCLIBDIR) -I $(LIB)

LIB			=	libft
LIBFT		=	$(LIB)/libft.a

SRCDIR		=	src
INCDIR		=	inc
INCLIBDIR	=	libft/inc
OBJDIR		=	obj

SRC			=	main utils exec
SRCS		=	$(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRC)))
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC:=.o))


all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Compilation de $(NAME) terminée."

$(LIBFT):
	@$(MAKE) --quiet -C $(LIB)
	@echo "Libft compilée."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilation de $<"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) --quiet -C $(LIB) clean
	@echo "Nettoyage des fichiers objets."

fclean: clean
	@rm -f $(NAME) $(NAMEBONUS)
	@$(MAKE) --quiet -C $(LIB) fclean
	@echo "Nettoyage complet."

re: fclean all

norminette:
	@echo "Norminette de $(NAME) dans $(SRCDIR) et $(INCDIR)..."
	@if norminette $(SRCDIR)/*.c $(INCDIR)/*.h | grep -v "OK!" | grep -q "Error!"; then \
		norminette $(SRCDIR)/*.c $(INCDIR)/*.h | grep -v "OK!" | \
		while read line; do \
			if echo $$line | grep -q "Error!"; then \
				echo "\033[0;31m$$line\033[0m"; \
			else \
				echo "$$line"; \
			fi; \
		done; \
	else \
		echo "\033[0;32mAll files are norminette friendly !\033[0m"; \
	fi

.PHONY: all clean fclean re norminette bonus