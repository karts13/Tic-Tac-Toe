CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++11 -march=native -O2
NCURSES_LIBS := -lncurses

TARGET := tictactoe

SRC := main.cpp tictactoe.cpp helper.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(NCURSES_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
