ROCK_PAPER_SCISSORS = rps
ROCK_PAPER_SCISSORS_COMPILE_FLAGS = -Wall -Wextra -Werror
ROCK_PAPER_SCISSORS_SRC = rock_paper_scissors.c
ROCK_PAPER_SCISSORS_OBJ = $(ROCK_PAPER_SCISSORS_SRC:.c=.o)

.PHONY: all clean fclean re

all: $(ROCK_PAPER_SCISSORS) 

$(ROCK_PAPER_SCISSORS): $(ROCK_PAPER_SCISSORS_OBJ)
	cc -o $(ROCK_PAPER_SCISSORS) $(ROCK_PAPER_SCISSORS_COMPILE_FLAGS) $(ROCK_PAPER_SCISSORS_OBJ)

$(ROCK_PAPER_SCISSORS_OBJ): $(ROCK_PAPER_SCISSORS_SRC)
	cc -c -I $(ROCK_PAPER_SCISSORS_COMPILE_FLAGS) $(ROCK_PAPER_SCISSORS_SRC)

clean:
	rm -f $(ROCK_PAPER_SCISSORS_OBJ)

fclean: clean
	rm -f $(ROCK_PAPER_SCISSORS) $(CLIENT_NAME)

re: fclean all
