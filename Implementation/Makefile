PROJECT_NAME=a
TEST_NAME=TEST_$(PROJECT_NAME)
FILE_LIST = account_signup.c account_signin.c read.c write.c  
COVERAGE_NAME=coverage_$(PROJECT_NAME)

ifdef OS
	RM = del /q
	FixPath=$(subst /,\,$1)
	EXEC=exe
	editor=notepad
else
	ifeq ($(shell uname), Linux)
		RM=rm -rf
		FixPath=$1
			EXEC=out
			editor=cat
	endif
endif


.PHONY : all test coverage run clean doc

$(PROJECT_NAME) :  
	gcc main.c  -I -c $(FILE_LIST) -o $(call  FixPath,$(PROJECT_NAME).$(EXEC))
run: $(PROJECT_NAME)
	./$(PROJECT_NAME).$(EXEC)


clean:
	$(RM) *.$(EXEC)
	$(RM) *.gcn
	$(RM) *.gcov
	$(RM) *.gcda
	$(RM) *.gcno