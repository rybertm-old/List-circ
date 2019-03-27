#ifndef LISTA_CIRC_H
#define LISTA_CIRC_H

#include <iostream>

template <typename T>
class lista_circ
{
private:
	struct noh
	{
		T m_dado;
		noh *m_prox;
	};

	noh *m_head;

public:
	lista_circ();
	~lista_circ();

	void insere(const T &dado);
	void remove(const T &dado);
	void remove(const noh *dado);
	void imprime();
	noh *buscar(const T &valor);
	void esvazia();
	int comprimento();
	void troca(const T &original, const T &novo);
};

#endif // LISTA_CIRC_H
