NAME = Intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRCS =	srcs/main.cpp \
		srcs/Bureaucrat.cpp \
		srcs/AForm.cpp \
		srcs/ShrubberyCreationForm.cpp \
		srcs/RobotomyRequestForm.cpp \
		srcs/PresidentialPardonForm.cpp \
		srcs/Intern.cpp

OBJDIR = objs
OBJS = $(patsubst srcs/%.cpp,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: srcs/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
