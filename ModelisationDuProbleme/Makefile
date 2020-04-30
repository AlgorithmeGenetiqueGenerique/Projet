run : main
	./main

main : main.o individu.o evaluation.o operations_genetiques.o gene.o EntreesSorties.o
	g++ -o main main.o individu.o evaluation.o operations_genetiques.o gene.o EntreesSorties.o
main.o : main.cpp
	g++ -c main.cpp
evaluation.o : evaluation.cpp evaluation.h individu.h
	g++ -c evaluation.cpp
operations_genetiques.o : operations_genetiques.cpp operations_genetiques.h individu.h
	g++ -c operations_genetiques.cpp
individu.o : individu.cpp individu.h
	g++ -c individu.cpp
gene.o : gene.cpp gene.h 
	g++ -c gene.cpp
EntreesSorties.o : EntreesSorties.cpp EntreesSorties.o
	g++ -c EntreesSorties.cpp
clean :
	rm -f main main.o individu.o operations_genetique.o operations_genetiques.o evaluation.o gene.o EntreesSorties.o
	clear
