#include "lista_circ.h"
#include <iostream>

int main()
{
	lista_circ<int> lista, lista2;
	lista.insere(9);
	lista.insere(2);
	lista.imprime();
	lista.troca(9, 1);
	lista.imprime();

	lista.insere(3);
	lista.insere(4);

	std::cout << "comprimento: " << lista.comprimento() << std::endl;
	lista.imprime();

	lista.remove(lista.buscar(4));

	lista.imprime();

	lista.esvazia();

	lista.imprime();
	getchar();

	return 0;
}