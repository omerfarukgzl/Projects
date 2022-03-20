hepsi : derle calistir

derle:
	g++ -I ./include/ -o ./lib/Avl.o -c ./src/Avl.cpp
	g++ -I ./include/ -o ./lib/DosyaIslem.o -c ./src/DosyaIslem.cpp
	g++ -I ./include/ -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp
	g++ -I ./include/ -o ./bin/test.exe ./lib/Avl.o ./lib/DosyaIslem.o ./lib/DogruKuyrugu.o ./src/main.cpp
	
calistir:
	./bin/test.exe