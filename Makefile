NAME=		libargc.a

##
##		RESSOURCES
##

SRC_PATH=	src

OBJ_PATH=	obj

CPPFLAGS=	-Iinclude

SRC_NAME=	ft_putcharfd.c\
			ft_putstrfd.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strcmp.c\
			ft_atoi.c\
			ft_putnbrfd.c\
			\
			ft_argnew.c\
			ft_argdel.c\
			ft_argpushf.c\
			ft_argpushb.c\
			ft_argprint.c\
			\
			ap_new.c\
			ap_del.c\
			ap_duplicate.c\
			ap_pushb.c\
			ap_addrule.c\
			ap_parse.c\
			ap_printfd.c\
			\
			parsednew.c\
			parseddel.c\
			\

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -Werror -g -fsanitize=address

CC=			gcc

LDFLAGS=

LIBS=

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		Compile using the lib's name to compile normally.
##		Compile with test for special testing purposes.
##

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ);\
				ranlib $(NAME)
				@echo "compiled $@."

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)


test:			$(NAME)
				$(CC) $(CFLAGS) -o argctest test.c  $(CPPFLAGS) -L. -largc

retest:			tclean test

##
##		Use fclean to clean this program.
##

clean:
				@rm -Rf $(OBJ_PATH)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

tclean:			fclean
				@rm argctest
				@echo "tclean"

re:				fclean all

.PHONY:			all clean fclean re
