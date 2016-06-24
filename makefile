main: main.o escuadron.o soldados.o corazaDura.o asesinoOculto.o arqueros.o
	g++ main.o escuadron.o soldados.o corazaDura.o asesinoOculto.o arqueros.o -o escuadron
	
main.o:	main.cpp escuadron.h soldados.h corazaDura.h asesinoOculto.h arqueros.h
	g++ -c main.cpp

escuadron.o:	escuadron.cpp escuadron.h soldados.h
	g++ -c escuadron.cpp

soldados.o:	soldados.cpp soldados.h
	g++ -c soldados.cpp

corazaDura.o:	corazaDura.cpp corazaDura.h soldados.h
	g++ -c corazaDura.cpp

asesinoOculto.o:	asesinoOculto.cpp asesinoOculto.h soldados.h
	g++ -c asesinoOculto.cpp

arqueros.o:	arqueros.cpp arqueros.h soldados.h
	g++ -c arqueros.cpp