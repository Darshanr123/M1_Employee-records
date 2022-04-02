PROJECT_NAME = Employee-Records

#All Source code file
SRC = main.c\
src/function.c


#Path to the header file
INC_HEADER = inc

#To check if the OS is windows or linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif


all:
	gcc -I $(INC_HEADER) $(SRC) -o $(call FixPath, ./$(PROJECT_NAME).$(EXEC))

run: all
	$(call FixPath, ./$(PROJECT_NAME).$(EXEC))
	

coverageCheck:
	gcc -fprofile-arcs -ftest-coverage -I $(INC_HEADER) -I $(INC_TEST) $(TEST_SRC) -o $(call FixPath, $(TEST_OUTPUT))
	$(call FixPath, ./$(TEST_OUTPUT))
	gcov -a $(call FixPath, ./test_Managment.c)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT

cppcheck:
	cppcheck --enable=all -I $(INC_HEADER) $(SRC)


clean:
	gcc -fprofile-arcs -ftest-coverage -I $(INC_HEADER) -I $(INC_TEST)  -o $(call FixPath)
	$(RM) *.$(EXEC)
	$(RM) *.gcda

