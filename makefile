//alaaamer0508@gmail.com

GCC = g++
CFLAGS = -std=c++11 -Wall -Wextra

SRC = main.cpp graph.cpp algorithms.cpp queue.cpp unionFind.cpp
OBJ = $(SRC:.cpp = .o)
EXEC = Main

TEST_SRC = test.cpp graph.cpp algorithms.cpp queue.cpp unionFind.cpp
TEST_EXEC = tests

.PHONY : all clean run test valgrind

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(GCC) $(CFLAGS) -o $@ $^

run : &(EXEC)
	./$(EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC):
	$(GCC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_SRC)

valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

clean:
	rm -f *.o $(EXEC) $(TEST_EXEC)			