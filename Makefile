shop : main.c product.o manager.o
	gcc -o shop main.c product.o manager.o
product.o : product.c product.h
	gcc -c product.c
manager.o : manager.c manager.h
	gcc -c manager.c
clean :
	rm *.o shop 	
