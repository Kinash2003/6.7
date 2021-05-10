// lab6.7
#include <iostream>
#include <Windows.h>
using namespace std;

class IFilter {
public:
	virtual bool operator () (int k) = 0;
};

struct Array {
	int* start;
	int size;
};
template <class T>
void Merge(T A[], int count) {

	
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

void ShowArray(Array a) {
	for (int i = 0; i < a.size; i++) {
		cout << *(a.start + i) << " ";
	}
	cout << endl;
}

Array Merge_if(Array a, Array b) {
	Array result;
	result.size = a.size + b.size;
	result.start = new int[result.size];
	int* ptr_a = a.start;
	int* ptr_b = b.start;
	int* ptr_result = result.start;
	for (; ptr_a < a.start + a.size && ptr_b < b.start + b.size; ) {
		if ((*ptr_a) > (*ptr_b)) {
			*ptr_result = *ptr_a;
			ptr_a++;
			ptr_result++;
		}
		else {
			*ptr_result = *ptr_b;
			ptr_b++;
			ptr_result++;
		}
	}
	if (ptr_a == a.start + a.size) {
		for (; ptr_b < b.start + b.size; ptr_b++, ptr_result++) {
			*ptr_result = *ptr_b;
		}
	}
	else {
		for (; ptr_a < a.start + a.size; ptr_a++, ptr_result++) {
			*ptr_result = *ptr_a;
		}
	}
	return result;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Сортування: " << endl;
	int M[] = { 87, 6, -1, -4, -9, 7, 5, 23 };
	Merge(M, 8);

	for (int i = 0; i < 8; i++)
		cout << M[i] << ", ";
	cout << endl;
	Array a = { new int[3]{ 9, 8, 1 }, 3 };
	Array b = { new int[3]{ 8, 9, 0}, 3 };
	Array r = Merge_if(a, b);
	ShowArray(r);
	delete[] a.start;
	return 0;
}