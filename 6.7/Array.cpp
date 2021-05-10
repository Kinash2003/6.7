#include <stdexcept>
#include <exception>

#include "Array.h"


//����������� ��� ��������� ����������(������) �� ���� ���������� - �������
Array::Array(const Array::size_type& n)
throw(std::bad_alloc, std::invalid_argument) {	//������������ �������
	first = 0;
	count = size = n;
	elems = new value_type[size];
	for (UINT i = 0; i < size; i++)
		elems[i] = 0;
}

//����������� ��� ��������� ����������(������) �� ���� ����������� - first � last
Array::Array(const iterator i_first, const iterator i_last)
throw(std::bad_alloc, std::invalid_argument) {	//������������ �������
	first = 0;
	if (i_first <= i_last) {
		count = size = (i_last - i_first) + 1;
		elems = new value_type[size];
		for (UINT i = 0; i < size; ++i)
			elems[i] = 0;
	}
	else
		throw std::invalid_argument("!!!");
}

//����������� ��� ��������� ����������(������) �� ���� ����������� - first � last
Array::Array(const size_type i_first, const size_type i_last)
throw(std::bad_alloc, std::invalid_argument) {	//������������ �������
	if (i_first <= i_last) {
		first = i_first;
		count = size = (i_last - i_first) + 1;
		elems = new value_type[size];
		for (UINT i = 0; i < size; ++i)
			elems[i] = 0;
	}
	else
		throw std::invalid_argument("!!!");
}

//����������� ���������(�� ������ ���������� �� ������)
Array::Array(const Array& t) throw(std::bad_alloc)	//������������ �������
	: size(t.size), count(t.count), first(t.first), elems(new value_type[size]) {
	for (UINT i = 0; i < size; ++i)
		elems[i] = t.elems[i];
}

//���������� - ��� ��������� ���'��, ��� ������� ��� ����������(������)
Array::~Array() {
	delete[]elems;
	elems = 0;
}

Array& Array::operator =(const Array& t) {	//�������������� �������� ���������
	Array tmp(t);
	Swap(tmp);
	return *this;
}

Array::size_type Array::Size() const {	//������� ����� ��� ��������(�����)
	return size;
}
Array::size_type Array::Capacity() const {	//������� �������� � ���������(�����)
	return count;
}

//�������� �� �������� �������� � ���������(�����)
bool Array::Empty() const {
	return count == 0;
}

//������ ����� ����������(������)
void Array::Resize(size_type newsize) throw(std::bad_alloc) {
	if (newsize > Capacity()) {
		value_type* data = new value_type[newsize];
		for (size_type i = 0; i < count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		size = newsize;
	}
}

//������ �� �������� ����������(������) --- ������(����� ����������)
Array::reference Array::operator [](size_type index) throw(std::out_of_range) {
	if ((first <= index) && (index <= first + size))
		return elems[index - first];
	else
		throw std::out_of_range("Index out of range!");
}

//"conts" ������ �� �������� ����������(������) --- ������(����� ����������)
Array::const_reference Array::operator [](size_type index) const
throw(std::out_of_range) {		//������������ �������
	if ((first <= index) && (index <= first + size))
		return elems[index - first];
	else
		throw std::out_of_range("Index out of range!");
}

void Array::Push_back(const value_type& v) {	//�������� ������� � �����
	if (count == size)		//���� ����
		Resize(size * 2);	//�������� "�������"
	elems[count++] = v;		//��������
}

//�������� ������� �������
void Array::Pop_back() throw(std::bad_alloc) {
	if (Size() > 0) {
		int* obj = new int[Size() - 1];
		for (size_t i = 0; i < Size() - 1; ++i)
			obj[i] = elems[i];
		delete[] elems;
		elems = obj;
		size = count = Size() - 1;
	}
}

void Array::Swap(Array& other) {	//������� � ������ �������
	std::swap(elems, other.elems);	//���������� ������� �����
	std::swap(size, other.size);
}

//������ ������� ������ ����� � ����������� ���� ������
std::ostream& operator <<(std::ostream& out, const Array& obj) {
	out << "\nData output: ";
	for (size_t j = 0; j < obj.count; j++)
		out << obj[j] << " ";
	return out;
}

//������ ������� ��� ����� � ����������� ���� �����
std::istream& operator >>(std::istream& in, const Array& obj) {
	std::cout << "\nData entry: ";
	for (size_t i = 0; i < obj.Size(); i++) {
		std::cout << "arr[" << i << "] = ";
		in >> obj[i];
	}
	return in;
}