#include <iostream>

#include "Algoritme.h"


//��������� ������ Search_End() - ����� ��� ��������
template<class T>
void Search_End(T* end, T* to) {
	T* from = end - 10;		//������� ��������� 4 �������� ����������(������)
	for (; from < end; from++) {		// from - �������� �������� ����������
		*to = *from;	// ��������� �������
		to++;			//�������� �� �������� �������
	}
}

//��������� ������ search_end_if() - ����� ��� ��������, �� ������������� ����


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