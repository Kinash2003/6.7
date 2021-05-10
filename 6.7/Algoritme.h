#pragma once

// ���������, �� ����� �������� - ����� ���������
template<class T>
class Predicate {
public:
	virtual bool operator () (T x) = 0;		//������ ���������� �����(����������� �����)
};


// �������� ��������� ��������� - ��������, �� �������� �������
template<class T>
class Positive : public Predicate<T> {	//����-������� - ������������ �� �����(����������) "Predicate" - ���������
public:
	virtual bool operator () (T x) {	//��������� �������������� �������� ()
		return x ;
	}
};

