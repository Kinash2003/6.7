#include <iostream>

#include "Algoritme.h"


//алгоритми пошуку Search_End() - серед вс≥х елемент≥в
template<class T>
void Search_End(T* end, T* to) {
	T* from = end - 10;		//останне входженн€ 4 елемент≥в контейнера(масива)
	for (; from < end; from++) {		// from - ≥тератор вх≥дного контейнера
		*to = *from;	// скоп≥ювали елемент
		to++;			//перейшли на наступну позиц≥ю
	}
}

//алгоритми пошуку search_end_if() - серед тих елемент≥в, €к≥ задовольн€ють умов≥


template <class T>
void Search_End_if(T A[], int count)
{
	int i, j;
	T tmp;
	for (i = 0; i < count - 1; i++)
		for (j = i; j >= 0; j--)
			if (A[j] < A[j + 1])
			{

				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
}

/*
T tmp;
for (i = 0;  i < count - 1; i++)
	for (j = i; j >= 0; j--)
		if (A[j] < A[j + 1])
		{

			tmp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = tmp;
		}
*/