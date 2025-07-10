NAME = serialize
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Data.cpp Serializer.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

$(OBJ): $(SRC)
	$(CXX) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
