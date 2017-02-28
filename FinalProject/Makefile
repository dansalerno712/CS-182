NAME = finalproject
TARBALL = dsalern1-$(NAME).tar.gz
SRC = hero.cpp main.cpp print.cpp nextNeighbor.cpp unvisit.cpp dfs.cpp add.cpp Dungeon.cpp bfs.cpp mst.cpp pizzaparty.cpp lucrativepath.cpp hhcomp.cpp sorting.hh tools.cpp insert.cpp merge.cpp raid.cpp
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
