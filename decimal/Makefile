CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11
GFLAGS = -fprofile-arcs -ftest-coverage
SRC = s21_decimal.c arithmetic/s21_add.c  arithmetic/s21_div.c  arithmetic/s21_mul.c comparison/s21_comparison.c convertors/s21_convertors.c others/s21_others.c
OBJ = $(SRC:.c=.o)
LIB = s21_decimal.a

LDFLAGS = $(shell pkg-config --libs check)
INCLUDES = $(shell pkg-config --cflags check)

TEST_DIR = tests
TEST_MAIN = $(TEST_DIR)/test.c
TEST_SRC = $(wildcard $(TEST_DIR)/suite_*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXE = test

.PHONY: all clean test s21_decimal.a gcov_report

all: s21_decimal.a

s21_decimal.a: $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 


$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: clean $(TEST_OBJ) $(TEST_MAIN:.c=.o)
	$(CC) $(CFLAGS) $(GFLAGS) -c s21_decimal.c -o s21_decimal.o
	$(CC) $(CFLAGS) $(GFLAGS) -c arithmetic/s21_add.c -o arithmetic/s21_add.o
	$(CC) $(CFLAGS) $(GFLAGS) -c arithmetic/s21_div.c -o arithmetic/s21_div.o
	$(CC) $(CFLAGS) $(GFLAGS) -c arithmetic/s21_mul.c -o arithmetic/s21_mul.o
	$(CC) $(CFLAGS) $(GFLAGS) -c comparison/s21_comparison.c -o comparison/s21_comparison.o
	$(CC) $(CFLAGS) $(GFLAGS) -c convertors/s21_convertors.c -o convertors/s21_convertors.o
	$(CC) $(CFLAGS) $(GFLAGS) -c others/s21_others.c -o others/s21_others.o
	ar rcs s21_decimal.a *.o arithmetic/*.o comparison/*.o convertors/*.o others/*.o

	$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) $(TEST_OBJ) $(TEST_MAIN:.c=.o) $(LIB) -o $(TEST_EXE) $(LDFLAGS)
	./$(TEST_EXE)

gcov_report: test 
	gcov -o arithmetic/ s21_add.c s21_div.c s21_mul.c
	gcov -o comparison/ s21_comparison.c
	gcov -o convertors/ s21_convertors.c
	gcov -o others/ s21_others.c


	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory lcov-report
	open lcov-report/index.html


clean:
	rm -f $(OBJ) $(LIB) $(TEST_OBJ) $(TEST_MAIN:.c=.o) $(TEST_EXE)
	find . -type f \( -name "*.gcno" -o -name "*.gcda" -o -name "*.gcov" \) -delete
	rm -rf lcov-report
	rm -f coverage.info