NAME = mysbbst
TARBALL = dsalern1-$(NAME).tar.gz
SRC = comparators.cpp search.cpp height.cpp print.cpp add.cpp main.cpp order.cpp remove.cpp student.hh
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all

submit: fclean
	tar cvzf $(TARBALL) *
