
Function_file =   6-hash_table_delete.c
Main_file =  6-hash_table_deletemain.c
NAME = 6-hash_table_delete
Function_name =  void hash_table_delete(hash_table_t *ht);


Header = hash_tables.h
Directory = singly_linked_lists






CC = gcc
Function_file_final =   '$(Function_file)' | tr -d '0123456789-'  
SRC =    $(Main_file) $(Function_file)  
OBJ = $(SRC:.c=.o)
RM = rm
git = git add * && git commit -m '$(NAME)' && git push
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89  
Final_header = \#include \"$(Header)\"
ReadMe = README.md


all: $(OBJ)
	$(CC)  $(CFLAGS)  $(OBJ) -o  $(NAME)
	betty    $(Main_file)  $(Header) $(Function_file)  
	valgrind ./$(NAME) 
	$(RM) -rf $(OBJ) $(NAME)
	



.PHONY: clean oclean fclean re brk  echo valgrind folder

clean:
	$(RM) -rf *~  $(NAME)

oclean:
	$(RM) -rf $(OBJ) $(NAME)

fclean:
	$(RM) -rf *~  $(NAME)
	$(RM) -rf $(OBJ)
	rm $(SRC)
re: oclean  all

folder:
	mkdir $(Directory)
	cd $(Directory)
	touch $(ReadMe)

git:
	$(git)

echo:
	
	echo  $(NAME)

valgrind:
	valgrind ./$(NAME)

brk:
	touch $(SRC) 
	grep -v '#endif' $(Header) > temp_file && mv temp_file $(Header)
	echo  "$(Function_name)"  >> "$(Header)"
	echo  "#endif"  >> "$(Header)"

	echo "$(Final_header)" >> "$(Function_file)"
	echo      ""            >> "$(Function_file)"
	echo  "/**"               >> "$(Function_file)"
	echo    " *"            >> "$(Function_file)"
	echo     $(Function_file_final)            >> "$(Function_file)"
	echo    " - Algorithms function"            >> "$(Function_file)"
	echo  " *@: pointer"              >> "$(Function_file)"
	echo  " *@: pointer"              >> "$(Function_file)"
	echo  " *"            >> "$(Function_file)"
	echo  " *Return: 1 or 0"             >> "$(Function_file)"
	echo  " */"            >> "$(Function_file)"
	echo      ""            >> "$(Function_file)"
	echo      ""            >> "$(Function_file)"
	echo      ""            >> "$(Function_file)"
	echo  "/**"   >> "$(Function_file)"
	echo  " * To-Do :  Variables Description"   >> "$(Function_file)"
	echo  " *          Formt document"   >> "$(Function_file)"
	echo  " */"   >> "$(Function_file)"