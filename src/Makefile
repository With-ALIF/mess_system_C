all: MessSystem

MessSystem: main.o auth.o student.o meal.o billing.o file_handler.o
	gcc main.o auth.o student.o meal.o billing.o file_handler.o -o MessSystem

main.o: main.c auth.h student.h meal.h billing.h file_handler.h
	gcc -c main.c

auth.o: auth.c auth.h student.h meal.h billing.h file_handler.h
	gcc -c auth.c

student.o: student.c student.h file_handler.h billing.h
	gcc -c student.c

meal.o: meal.c meal.h student.h
	gcc -c meal.c

billing.o: billing.c billing.h student.h file_handler.h meal.h
	gcc -c billing.c

file_handler.o: file_handler.c file_handler.h student.h
	gcc -c file_handler.c

clean:
	rm -f *.o MessSystem
