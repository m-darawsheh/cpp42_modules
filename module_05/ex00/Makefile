NAME = outfile 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRCS  = main.cpp Bureaucrat.cpp
OBJS  = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re