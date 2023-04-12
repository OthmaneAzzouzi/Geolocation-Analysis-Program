# Makefile

#OPTIONS = -Wall           # option standard
#OPTIONS = -g -O0 -Wall    # pour rouler dans gdb
OPTIONS = -O2 -Wall    # pour optimiser

all : main

main : main.cpp personne.h personne.o coordonnees.h coordonnees.o
	g++ ${OPTIONS} -o main main.cpp coordonnees.o personne.o
	
personne.o : personne.cpp personne.h
	g++ ${OPTIONS} -c -o personne.o personne.cpp

coordonnees.o : coordonnees.cpp coordonnees.h
	g++ ${OPTIONS} -c -o coordonnees.o coordonnees.cpp

clean:
	rm -rf tp2 *~ *.o


