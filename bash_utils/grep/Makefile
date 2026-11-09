GCC = -Wall -Wextra -Werror -std=c11

TEST_FILE = test.txt
TEST_FILE2 = test2.txt
TEST_T = t.txt
S21_EXE = ./s21_grep
EXE = grep
FLAGS = e i v c l n
FLAGS2 = h s o
ALL_FLAGS = i v c l n h s o
TEMPLATE = at
DIFF = diff -u

all: clean s21_grep

s21_grep: Makefile s21_grep.h s21_grep.c
	gcc $(GCC) s21_grep.c -o s21_grep

clean:
	rm -rf s21_grep

rebuild:
	make clean
	make all

test: $(S21_EXE)
	@echo "TESTING"
	@echo "part 2"
	@for flag in $(FLAGS); do \
		$(S21_EXE) -$$flag $(TEMPLATE) $(TEST_FILE) > s21_exe.txt; \
		$(EXE) -$$flag $(TEMPLATE) $(TEST_FILE) > exe.txt; \
		$(DIFF) s21_exe.txt exe.txt > /dev/null && \
			echo "PASS -$$flag" || \
			echo "FAIL -$$flag"; \
	done

	@echo "part 3"
	@for flag in $(FLAGS2); do \
    	$(S21_EXE) -$$flag $(TEMPLATE) $(TEST_FILE) > s21_exe.txt; \
    	$(EXE) -$$flag $(TEMPLATE) $(TEST_FILE) > exe.txt; \
    	$(DIFF) s21_exe.txt exe.txt > /dev/null && \
    		echo "PASS -$$flag" || \
    		echo "FAIL -$$flag"; \
    done
	@$(S21_EXE) -f $(TEST_T) $(TEST_FILE) > s21_exe.txt;
	@$(EXE) -f $(TEST_T) $(TEST_FILE) > exe.txt;
	@$(DIFF) s21_exe.txt exe.txt > /dev/null && echo "PASS -f" || echo "FAIL -f";

	@echo "part4"
	@for flag1 in $(ALL_FLAGS); do \
		for flag2 in $(ALL_FLAGS); do \
			if [ "$$flag1" != "$$flag2" ]; then \
				$(S21_EXE) -$$flag1 -$$flag2 $(TEMPLATE) $(TEST_FILE) > s21_exe.txt; \
				$(EXE) -$$flag1 -$$flag2 $(TEMPLATE) $(TEST_FILE) > exe.txt; \
				$(DIFF) s21_exe.txt exe.txt > /dev/null && \
					echo "PASS -$$flag1 -$$flag2" || \
					echo "FAIL -$$flag1 -$$flag2"; \
			fi \
		done \
	done

	@echo "2 FILES"
	@for flag in $(FLAGS); do \
    		$(S21_EXE) -$$flag $(TEMPLATE) $(TEST_FILE) $(TEST_FILE2) > s21_exe.txt; \
    		$(EXE) -$$flag $(TEMPLATE) $(TEST_FILE) $(TEST_FILE2) > exe.txt; \
    		$(DIFF) s21_exe.txt exe.txt > /dev/null && \
    			echo "PASS -$$flag" || \
    			echo "FAIL -$$flag"; \
    	done
	@for flag in $(FLAGS2); do \
        	$(S21_EXE) -$$flag $(TEMPLATE) $(TEST_FILE) $(TEST_FILE2) > s21_exe.txt; \
        	$(EXE) -$$flag $(TEMPLATE) $(TEST_FILE) $(TEST_FILE2) > exe.txt; \
        	$(DIFF) s21_exe.txt exe.txt > /dev/null && \
        		echo "PASS -$$flag" || \
        		echo "FAIL -$$flag"; \
        done
	@$(S21_EXE) -f $(TEST_T) $(TEST_FILE) $(TEST_FILE2) > s21_exe.txt;
	@$(EXE) -f $(TEST_T) $(TEST_FILE) $(TEST_FILE2) > exe.txt;
	@$(DIFF) s21_exe.txt exe.txt > /dev/null && echo "PASS -f" || echo "FAIL -f";
	@for flag1 in $(ALL_FLAGS); do \
    		for flag2 in $(ALL_FLAGS); do \
    			if [ "$$flag1" != "$$flag2" ]; then \
    				$(S21_EXE) -$$flag1 -$$flag2 $(TEMPLATE) $(TEST_FILE) $(TEST_FILE2) > s21_exe.txt; \
    				$(EXE) -$$flag1 -$$flag2 $(TEMPLATE) $(TEST_FILE) $(TEST_FILE2) > exe.txt; \
    				$(DIFF) s21_exe.txt exe.txt > /dev/null && \
    					echo "PASS -$$flag1 -$$flag2" || \
    					echo "FAIL -$$flag1 -$$flag2"; \
    			fi \
    		done \
    	done

	@rm -f s21_exe.txt exe.txt
	@echo "TESTING COMPLETE"