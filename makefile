tree_user: user_interface.o library.o
	gcc -Wall -o tree_user user_interface.o library.o

tree_file: file_interface.o library.o
	gcc -Wall -o tree_file file_interface.o library.o

library.o: library.c library.h
	gcc -Wall -c library.c

text_interface.o: file_interface.c library.h
	gcc -Wall -c file_interface.c

user_interface.o: user_interface.c library.h
	gcc -Wall -c user_interface.c


clean:
	rm -f tree_file file_interface.o tree_user user_interface.o library.o

