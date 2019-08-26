NAME :=			ft_printf

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/
LIB_DIR :=		./lib/

SRC :=			main.c ft_printf.c checker.c convert_num.c define_format.c f_init.c get_num_len.c glue.c handle_min_width.c handle_num_precision.c print_d.c print_c.c print_f.c print_o.c print_s.c print_u.c print_xX.c

OBJ =			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_INC :=	$(LIBFT_DIR)includes/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC :=			gcc
CC_FLAGS :=		-v

LINK_FLAGS :=	$(LIBFT_FLAGS)
HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)
	ar rc libftprintf.a $(OBJ)
	ranlib libftprintf.a

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean: 
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -fr $(OBJ_DIR)
	make fclean $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
