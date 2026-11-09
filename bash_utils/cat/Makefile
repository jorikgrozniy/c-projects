GCC = -Wall -Wextra -Werror -std=c11

TEST_FILE = test.txt
S21_EXE = ./s21_cat
EXE = cat
FLAGS = b e n s t v
DIFF = diff -u

all: clean s21_cat

s21_cat: Makefile s21_cat.h s21_cat.c
	gcc $(GCC) s21_cat.c -o s21_cat

clean:
	rm -rf s21_cat

rebuild:
	make clean
	make all

test: $(S21_EXE)
	@echo "TESTING"
	@echo "1 flag"
	@for flag in $(FLAGS); do \
		$(S21_EXE) -$$flag $(TEST_FILE) > s21_exe.txt; \
		$(EXE) -$$flag $(TEST_FILE) > exe.txt; \
		$(DIFF) s21_exe.txt exe.txt > /dev/null && \
			echo "PASS -$$flag" || \
			echo "FAIL -$$flag"; \
	done

	@echo "2 flags"
	@for flag1 in $(FLAGS); do \
		for flag2 in $(FLAGS); do \
			if [ "$$flag1" != "$$flag2" ]; then \
				$(S21_EXE) -$$flag1 -$$flag2 $(TEST_FILE) > s21_exe.txt; \
				$(EXE) -$$flag1 -$$flag2 $(TEST_FILE) > exe.txt; \
				$(DIFF) s21_exe.txt exe.txt > /dev/null && \
					echo "PASS -$$flag1 -$$flag2" || \
					echo "FAIL -$$flag1 -$$flag2"; \
			fi \
		done \
	done

	@echo "3 flags"
	@for flag1 in $(FLAGS); do \
    	for flag2 in $(FLAGS); do \
    		for flag3 in $(FLAGS); do \
    			if [ "$$flag1" != "$$flag2" ] && [ "$$flag1" != "$$flag3" ] && [ "$$flag3" != "$$flag2" ]; then \
    				$(S21_EXE) -$$flag1 -$$flag2 -$$flag3 $(TEST_FILE) > s21_exe.txt; \
    				$(EXE) -$$flag1 -$$flag2 -$$flag3 $(TEST_FILE) > exe.txt; \
    				$(DIFF) s21_exe.txt exe.txt > /dev/null && \
    					echo "PASS -$$flag1 -$$flag2 -$$flag3" || \
   						echo "FAIL -$$flag1 -$$flag2 -$$flag3"; \
   				fi \
   			done \
		done \
    done

	@echo "4 flags"
	@for flag1 in $(FLAGS); do \
		for flag2 in $(FLAGS); do \
        	for flag3 in $(FLAGS); do \
        		for flag4 in $(FLAGS); do \
        			if [ "$$flag1" != "$$flag2" ] && [ "$$flag1" != "$$flag3" ] && [ "$$flag1" != "$$flag4" ] && [ "$$flag2" != "$$flag3" ] && [ "$$flag2" != "$$flag4" ] && [ "$$flag3" != "$$flag4" ]; then \
        				$(S21_EXE) -$$flag1 -$$flag2 -$$flag3 -$$flag4 $(TEST_FILE) > s21_exe.txt; \
        				$(EXE) -$$flag1 -$$flag2 -$$flag3 -$$flag4 $(TEST_FILE) > exe.txt; \
        				$(DIFF) s21_exe.txt exe.txt > /dev/null && \
        					echo "PASS -$$flag1 -$$flag2 -$$flag3 -$$flag4" || \
       						echo "FAIL -$$flag1 -$$flag2 -$$flag3 -$$flag4"; \
       				fi \
       			done \
    		done \
        done \
	done

	@echo "all flags"
	@$(S21_EXE) -benstv $(TEST_FILE) > s21_exe.txt; \
	$(EXE) -benstv $(TEST_FILE) > exe.txt; \
	$(DIFF) s21_exe.txt exe.txt > /dev/null && \
		echo "PASS -benstv" || \
		echo "FAIL -benstv"

	@$(S21_EXE) -b -e -n -s -t -v $(TEST_FILE) > s21_exe.txt; \
	$(EXE) -b -e -n -s -t -v $(TEST_FILE) > exe.txt; \
	$(DIFF) s21_exe.txt exe.txt > /dev/null && \
		echo "PASS -b -e -n -s -t -v" || \
		echo "FAIL -b -e -n -s -t -v"

	@rm -f s21_exe.txt exe.txt
	@echo "TESTING COMPLETE"