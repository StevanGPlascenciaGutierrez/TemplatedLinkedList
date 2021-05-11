output:Plascencia-Gutierrez_conga.o Plascencia-Gutierrez_zombie.o Plascencia-Gutierrez_Stevan_assn6.o
	g++ -g -Wall  Plascencia-Gutierrez_conga.o Plascencia-Gutierrez_zombie.o Plascencia-Gutierrez_Stevan_assn6.o -o main
Plascencia-Gutierrez_Stevan_assn6.o:Plascencia-Gutierrez_Stevan_assn6.cpp Plascencia-Gutierrez_list.h Plascencia-Gutierrez_node.h
	g++ -g -c Plascencia-Gutierrez_Stevan_assn6.cpp

Plascencia-Gutierrez_conga.o:Plascencia-Gutierrez_conga.cpp Plascencia-Gutierrez_conga.h
	g++ -g -c Plascencia-Gutierrez_conga.cpp

Plascencia-Gutierrez_zombie.o: Plascencia-Gutierrez_zombie.cpp Plascencia-Gutierrez_zombie.h termcolor.hpp
	g++ -g -c Plascencia-Gutierrez_zombie.cpp

clean:
	rm *.o *~


