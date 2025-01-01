NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = main.cpp phonebook.cpp contact.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC	=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))



$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c: clean
f: fclean

.PHONY: all clean fclean f c