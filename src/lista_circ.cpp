#include "lista_circ.h"

#include <iostream>

template class lista_circ<int>;
template class lista_circ<float>;
template class lista_circ<double>;
template class lista_circ<char>;

template <typename T>
lista_circ<T>::lista_circ()
{
	m_head = new noh;
	m_head->m_prox = m_head;
}

template <typename T>
lista_circ<T>::~lista_circ()
{
	esvazia();
}

template <typename T>
void lista_circ<T>::insere(const T &dado)
{
	noh *tmp = new noh;
	tmp->m_dado = dado;

	noh *p = m_head;
	noh *q = m_head->m_prox;

	while (q != m_head)
	{
		p = q;
		q = q->m_prox;
	}

	tmp->m_prox = q;
	p->m_prox = tmp;
}

template <typename T>
void lista_circ<T>::remove(const T &dado)
{
	noh *p = m_head;
	noh *q = m_head->m_prox;

	while (q != m_head && q->m_dado != dado)
	{
		p = q;
		q = q->m_prox;
	}

	if (q != m_head)
	{
		p->m_prox = q->m_prox;
		delete q;
	}
}

template <typename T>
void lista_circ<T>::remove(const noh *dado)
{
	if (dado == m_head)
		return;

	noh *p = m_head;
	noh *q = m_head->m_prox;

	while (q->m_dado != dado->m_dado)
	{
		p = q;
		q = q->m_prox;
	}

	p->m_prox = q->m_prox;
	delete q;
}

template <typename T>
void lista_circ<T>::esvazia()
{
	noh *p = m_head;
	noh *q = m_head->m_prox;
	noh *r = q;

	while (q != m_head)
	{
		p->m_prox = q->m_prox;
		q = q->m_prox;
		delete r;
		r = q;
	}
	//delete p;
}

template <typename T>
void lista_circ<T>::imprime()
{
	noh *p = m_head;
	noh *q = m_head->m_prox;

	if (p == q)
		std::cout << "\nLista vazia." << std::endl;
	else
		while (q != m_head)
		{
			std::cout << q->m_dado << std::endl;
			q = q->m_prox;
		}
}

template <typename T>
typename lista_circ<T>::noh *lista_circ<T>::buscar(const T &valor)
{
	noh *q = m_head->m_prox;

	while (q != m_head && q->m_dado != valor)
	{
		q = q->m_prox;
	}

	return q;
}

template <typename T>
int lista_circ<T>::comprimento()
{
	noh *q = m_head->m_prox;

	int l = 0;

	while (q != m_head)
	{
		l++;
		q = q->m_prox;
	}

	return l;
}

template <typename T>
void lista_circ<T>::troca(const T &original, const T &novo)
{
	noh *p;
	noh *q = m_head->m_prox;

	while (q != m_head)
	{
		p = buscar(original);

		if (p != m_head)
			p->m_dado = novo;

		q = q->m_prox;
	}
}