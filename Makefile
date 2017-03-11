all:	cipher

cipher:	cipher.o Playfair.o Caesar.o Railfence.o RowTransposition.o Vigenere.o Hill.o
	g++ -std=c++11 cipher.o Playfair.o Caesar.o Railfence.o RowTransposition.o Vigenere.o Hill.o -o cipher

cipher.o:	cipher.cpp
	g++ -std=c++11 -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h 
	g++ -std=c++11 -g -c Playfair.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	g++ -std=c++11 -g -c Caesar.cpp

Railfence.o: Railfence.cpp Railfence.h CipherInterface.h
	g++ -std=c++11 -g -c Railfence.cpp

RowTransposition.o: RowTransposition.cpp RowTransposition.h CipherInterface.h
	g++ -std=c++11 -g -c RowTransposition.cpp

Vigenere.o: Vigenere.cpp Vigenere.h CipherInterface.h
	g++ -std=c++11 -g -c Vigenere.cpp

Hill.o: Hill.cpp Hill.h CipherInterface.h
	g++ -std=c++11 -g -c Hill.cpp

# Uncomment this code once you add the appropriate files
#RowTransposition.o:	RowTransposition.cpp RowTransposition.h
#	g++ -g -c RowTransposition.cpp


clean:
	rm -rf *.o cipher
