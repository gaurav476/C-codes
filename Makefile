//file with all the dependencies so that only a single command runs and you are free from the headache of giving all the filenames

all : MagicSq.o createMgcSq.o generateMgcSq.o validateMgcSq.o

	gcc MagicSq.o createMgcSq.o generateMgcSq.o validateMgcSq.o -o MagicSq


MagicSq.o : MagicSq.c createMgcSq.o generateMgcSq.o validateMgcSq.o CreateMgcSq.h GenerateMgcSq.h ValidateMgcSq.h

		gcc -c MagicSq.c



createMgcSq.o : createMgcSq.c

		gcc -c createMgcSq.c



generateMgcSq.o : generateMgcSq.c

		  gcc -c generateMgcSq.c




validateMgcSq.o : validateMgcSq.c

		  gcc -c validateMgcSq.c



clean :

	rm -rf *.o

	rm -rf MagicSq 
