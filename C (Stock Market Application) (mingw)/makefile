hepsi : derle calistir

derle:
	gcc -I ./include/ -o ./lib/Banka.o -c ./src/Banka.c
	gcc -I ./include/ -o ./lib/Portfoy.o -c ./src/Portfoy.c
	gcc -I ./include/ -o ./lib/Emir.o -c ./src/Emir.c
	gcc -I ./include/ -o ./lib/Hisse.o -c ./src/Hisse.c
	gcc -I ./include/ -o ./bin/test.exe ./lib/Banka.o ./lib/Emir.o ./lib/Hisse.o ./lib/Portfoy.o ./src/Main.c
	
calistir:
	./bin/test.exe