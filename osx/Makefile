NAME = libasm.a
TESTERNAME = give_me_two_str_n_a_file_to_open

#PATH
INCLUDE = ./includes
SRCPATH = ./src
OBJPATH = ./obj

NASM = nasm -fmacho64
CLANG = clang -Wextra -Werror -Wall

#SRCS
SRCS = $(addprefix $(SRCPATH)/, ft_read.s ft_write.s ft_strlen.s ft_strcmp.s \
	   ft_strdup.s ft_strcpy.s)

#OBJS
OBJ = $(SRCS:$(SRCPATH)/%.s=$(OBJPATH)/%.o)

#RULES
all : mk_objpath $(NAME)

mk_objpath :
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

$(OBJPATH)/%.o : $(SRCPATH)/%.s $(INCLUDE)
	$(NASM) $< -o $@

tester : all
	$(CLANG) -I $(INCLUDE) main.c $(NAME) -o $(TESTERNAME)

.PHONY : clean fclean re

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME) $(TESTERNAME)

re : fclean all
