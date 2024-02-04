CC=gcc -g3
SRC=s21_matrix_oop.cc
OBJ=s21_matrix_oop.o
CFLAGS=-Wall -Werror -Wextra --std=c++17 -lstdc++ -lm
TEST_FLAGS=-lgtest -lgcov

all: clean check-style gcov_report

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM

test: s21_matrix_oop.a
	$(CC) tests.cc s21_matrix_oop.a $(CFLAGS) $(TEST_FLAGS) -o test
	./test

s21_matrix_oop.a: clean
	$(CC) --coverage -c $(SRC)
	ar rcs s21_matrix_oop.a $(OBJ)
	ranlib s21_matrix_oop.a
	
gcov_report: test
	lcov -t test -o rep.info -c -d ./
	genhtml -o report rep.info
	open report/index.html

check-style:
	clang-format -n -style=Google *.h $(SRC_TESTS) $(SRC_FILES)
	
set-style:
	clang-format -i -style=Google *.h $(SRC_TESTS) $(SRC_FILES)


valgrind:
	valgrind --tool=memcheck --show-reachable=yes --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --num-callers=20 --show-leak-kinds=all ./test
