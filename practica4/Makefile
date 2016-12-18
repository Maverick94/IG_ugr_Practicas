# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica4

# banderas para el compilador (C y C++). Se indican los directorios donde se pueden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I. -std=c++11
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I. -std=c++11

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut -ljpeg

# definicion del compilador
#
CC = g++

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : practica4.o objetos.o file_ply_stl.o jpg_memsrc.o jpg_imagen.o jpg_readwrite.o
	$(CC) -o $@ $(CXXFLAGS) practica4.o objetos.o file_ply_stl.o jpg_memsrc.o jpg_readwrite.o jpg_imagen.o $(LDFLAGS)

#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
