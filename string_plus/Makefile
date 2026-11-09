CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
GFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = $(shell pkg-config --libs check)
INCLUDES = $(shell pkg-config --cflags check)

SRC = s21_string.c s21_sprintf.c s21_sscanf.c
OBJ = $(SRC:.c=.o)
LIB = s21_string.a

TEST_DIR = tests
TEST_MAIN = $(TEST_DIR)/tests.c
TEST_SOURCES = $(wildcard $(TEST_DIR)/test_*.c)
TEST_OBJECTS = $(patsubst %.c,%.o,$(TEST_SOURCES))
TARGET = test

.PHONY: all test clean rebuild gcov_report s21_string.a

all: $(LIB)

s21_string.a: $(OBJ)
	ar rcs $@ $^
	rm -rf *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


test: $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(TEST_MAIN) -o $(TEST_MAIN:.c=.o)
	for file in $(TEST_SOURCES); do \
		$(CC) $(CFLAGS) $(INCLUDES) -c $$file -o $${file%.c}.o; \
	done
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OBJECTS) $(TEST_MAIN:.c=.o) $(LIB) -o $(TARGET) $(LDFLAGS)
	./$(TARGET)
	@rm -f $(OBJ) $(TEST_OBJECTS) $(TEST_MAIN:.c=.o)


gcov_report:
	
	$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) -c s21_string.c -o s21_string.o
	$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) -c s21_sprintf.c -o s21_sprintf.o
	$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) -c s21_sscanf.c -o s21_sscanf.o
	ar rcs $(LIB) s21_string.o s21_sprintf.o s21_sscanf.o

	
	$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) -c $(TEST_MAIN) -o $(TEST_MAIN:.c=.o)
	for file in $(TEST_SOURCES); do \
		$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) -c $$file -o $${file%.c}.o; \
	done

	
	$(CC) $(CFLAGS) $(GFLAGS) $(INCLUDES) $(TEST_OBJECTS) $(TEST_MAIN:.c=.o) $(LIB) -o $(TARGET) $(LDFLAGS)
	./$(TARGET)
	@rm -f $(OBJ) $(TEST_OBJECTS) $(TEST_MAIN:.c=.o)

	gcov -a *.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory lcov-report
	open lcov-report/index.html

clean:
	rm -rf *.o *.a *.gcda *.gcno *.gcov $(TEST_DIR)/*.o $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcov $(TARGET) coverage.info lcov-report

rebuild: clean all