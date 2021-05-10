#pragma once

#include <iostream>


class Array {		//�������� ��������� ����� �������
public:
	//������� �� ������ ���� �����
	typedef unsigned int UINT;
	typedef int value_type;
	typedef int* iterator;
	typedef const int* const_iterator;
	typedef int& reference;
	typedef const int& const_reference;
	typedef std::size_t size_type;
private:
	static const size_type minsize = 10;	//��������� ����� ������
	size_type size;							//������� ����� ��� ��������
	size_type count;						//������� �������� � �����
	size_type first;						//�������� ������� ������� �������� � �����
	value_type* elems;						//�������� �� ���
public:
	//����������� ��� ��������� ����������(������) �� ���� ���������� - �������
	Array(const size_type& n = minsize)
		throw(std::bad_alloc, std::invalid_argument);	//������������ �������

	//����������� ��� ��������� ����������(������) �� ���� ����������� - first � last
	Array(const iterator first, const iterator last)
		throw(std::bad_alloc, std::invalid_argument);	//������������ �������

	//����������� ��� ��������� ����������(������) �� ���� ����������� - first � last
	Array(const size_type first, const size_type last)
		throw(std::bad_alloc, std::invalid_argument);	//������������ �������

	//����������� ���������(�� ������ ���������� �� ������)
	Array(const Array&)
		throw(std::bad_alloc);		//������������ �������

	~Array();	//���������� - ��� ��������� ���'��, ��� ������� ��� ����������(������)

	Array& operator=(const Array&);		//�������������� �������� ���������

	iterator Begin() { return elems; }	//�������� - ���� ����� �� ������� ����������(������)
	const_iterator Begin() const { return elems; }	// �������� "const" - ���� ����� �� ������� ����������(������)

	iterator End() { return elems + count; }	//�������� - ���� ����� �� ����� ����������(������)
	const_iterator End() const { return elems + count; }	// �������� "const" - ���� ����� �� ����� ����������(������)

	size_type Size() const;			//������� ����� ��� ��������(�����)
	size_type Capacity() const;		//������� �������� � ���������(�����)

	bool Empty() const;				//�������� �� �������� �������� � ���������(�����)
	void Resize(size_type newsize)	//������ ����� ����������(������)
		throw(std::bad_alloc);		//������������ �������

	//������ �� �������� ����������(������) --- ������(����� ����������)
	reference operator[](size_type) throw(std::out_of_range);
	//"conts" ������ �� �������� ����������(������) --- ������(����� ����������)
	const_reference operator[](size_type) const throw(std::out_of_range);

	reference Front() { return elems[0]; }
	const_reference Front() const { return elems[0]; }

	reference Back() { return elems[Size() - 1]; }
	const_reference Back() const { return elems[Size() - 1]; }

	void Push_back(const value_type& v);	//�������� ������� � �����
	void Pop_back();						//�������� ������� �������
	void clear() { count = 0; }				//�������� �����
	void Swap(Array& other);				//������� � ������ �������

	//������ ������� ������ ����� � ����������� ���� ������
	friend std::ostream& operator <<(std::ostream& out, const Array& a);
	//������ ������� ��� ����� � ����������� ���� �����
	friend std::istream& operator >>(std::istream& in, Array& a);
};