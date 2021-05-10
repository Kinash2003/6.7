#pragma once

// інтерфейс, що описує функтори - унарні предикати
template<class T>
class Predicate {
public:
	virtual bool operator () (T x) = 0;		//чистий віртуальний метод(абстрактний метод)
};


// реалізуємо інтерфейс функтором - перевірка, чи значення додатне
template<class T>
class Positive : public Predicate<T> {	//клас-функтор - успадкований від класу(інтерфейсу) "Predicate" - реалізація
public:
	virtual bool operator () (T x) {	//віртуальне перевантаження операції ()
		return x ;
	}
};

