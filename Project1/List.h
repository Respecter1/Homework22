#pragma once
/*
	1. Створіть шаблон на основі цього класу List:
*/

template<typename T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(T value);
	void append(T value);
	int is_present(T value) const;
	int is_empty() const
	{
		return head == 0;
	}
	T count() const { return theCount; }
private:
	class ListCell
	{
	public:
		ListCell(int value, ListCell* cell = 0) : val(value),
			next(cell) {}
		T val;
		ListCell* next;
	};
	T val;
	ListCell* next;
	ListCell* head;
	ListCell* tail;
	T theCount;
};

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::insert(T value)
{
}

template<typename T>
void List<T>::append(T value)
{
}

template<typename T>
int List<T>::is_present(T value) const
{
	return 0;
}
