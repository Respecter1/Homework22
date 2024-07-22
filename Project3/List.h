#pragma once
/*
	3. Ќапиш≥ть шаблонний вар≥ант виконанн€.
*/


template<typename T>
class List
{
private:

	void Copy(const List& other);//коп≥юЇ ≥нший список(цей метод зроблен дл€ уникненн€ дублюванн€ коду

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head; //вказ≥вник на голову 
	Node* tail; //хв≥ст
	size_t size;

public:
	class Iterator
	{
	public:
		Iterator(Node* node);

		bool operator!=(const Iterator& other) const;

		Iterator& operator++();
		Iterator operator++(int);
		T& operator*();
		T* operator->();


	private:
		Node* node;
	};

	// --- Constructors ---
	List();
	List(const List& other);
	List(List&& other) noexcept;

	// --- Destructor ---

	~List();

	// --- Insert method ---(методи вставки)

	void PushBack(const T& value);
	void PushFront(const T& value);

	// --- Remove methods ---(методи €к≥ видал€ють)

	void PopBack();//видалити з к≥нц€
	void PopFront();//видалити з початку 
	void Remove(const T& value);// видал€ти вузов вставл€ючи певне значенн€, буде шукати чи Ї цей вузов с таким значенн€м. якщо Ї тод≥ видал€Ї.
	void Clear();//все очищаЇ

	// --- Find methods ---

	bool Find(const T& value) const;// дл€ пошуку, в душках ми указуЇмо значенннн€ €ке треба знайти. ≤ будемо повертати [try] €кщо зннайшло [false] €кщо н≥  

	// --- —heck size methods ---(методи €к≥ перев≥р€ють розм≥р)

	bool IsEmpty() const;//перев≥р€Ї чи список €вл€Їтьс€ пустий 
	size_t Size() const;//повертаЇ розм≥р нашого списку

	// --- Assigment operator ---

	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;

	// --- Iteratore methods ---

	Iterator begin();
	Iterator end();

};

template<typename T>
void List<T>::Copy(const List<T>& other)//O(n)
{
	if (other.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;

	}
	else
	{
		head = new Node{ other.head->data,nullptr };//указуЇ на новий вузов

		Node* current = head;
		Node* otherCurrent = other.head;

		while (otherCurrent->next != nullptr)
		{
			current->next = new Node{ otherCurrent->next->data,nullptr };

			current = current->next;
			otherCurrent = otherCurrent->next;
		}
		tail = current;

		size = other.size;
	}




}

template<typename T>
List<T>::List()
	:head(nullptr), tail(nullptr), size(0)
{}

template<typename T>
List<T>::List(const List<T>& other)//O(n)
	: List()
{
	Copy(other);
}

template<typename T>
List<T>::List(List<T>&& other) noexcept//O(1)
	:head(other.head), tail(other.tail), size(other.size)
{
	other.head = nullptr;
	other.tail = nullptr;
	other.size = 0;
}

template<typename T>
List<T>::~List<T>()
{
	Clear();
}

template<typename T>
void List<T>::PushBack(const T& value)//O(1)
{
	if (head == nullptr)
	{
		head = new Node{ value,nullptr };
		tail = head;
	}
	else
	{
		tail->next = new Node{ value, nullptr };
		tail = tail->next;

	}

	size++;
}

template<typename T>
void List<T>::PushFront(const T& value)//O(1)
{
	if (head == nullptr)
	{
		head = new Node{ value,nullptr };
		tail = head;
	}
	else if (head == tail)
	{
		Node* newNode = new Node{ value, head };
		head = newNode;
		tail = head->next;
	}
	else
	{
		Node* newNode = new Node{ value, head };
		head = newNode;
	}
	size++;
}

template<typename T>
void List<T>::PopBack()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* previous = head;//попередн≥й
		Node* current = head->next;//данний

		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}

		delete current;
		previous->next = nullptr;
		tail = previous;
	}
	--size;
}

template<typename T>
void List<T>::PopFront()//O(1)
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node* newHead = head->next;
		delete head;
		head = newHead;
	}
	--size;
}

template<typename T>
void List<T>::Remove(const T& value)//O(n)
{
	Node* previous = nullptr;
	Node* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			if (previous == nullptr)//коли previous складаЇтьс€ лише с 1 елемента
			{
				head = head->next;

				// the beginning of the list 
				if (head == nullptr)
				{
					tail = nullptr;
				}
			}
			else
			{
				previous->next = current->next;

				// the end of list 
				if (current == tail)
				{
					tail = previous;
				}
			}

			delete current;
			--size;
			return;
		}
		previous = current;
		current = current->next;
	}
}

template<typename T>
void List<T>::Clear()//O(n)
{
	while (head != nullptr)
	{
		Node* current = head;
		head = head->next;

		delete current;
	}
	tail = nullptr;
	size = 0;
}

template<typename T>
bool List<T>::Find(const T& value) const//O(n)
{
	if (head == nullptr)
	{
		return false;
	}

	Node* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			return true;
		}

		current = current->next;
	}
	return false;
}

template<typename T>
bool List<T>::IsEmpty() const
{
	return head == nullptr;
}

template<typename T>
size_t List<T>::Size() const
{
	return size;
}

template<typename T>
List<T>& List<T>::operator=(const List& other)
{
	if (this != &other)
	{
		Clear();
		Copy(other);
	}

	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List<T>&& other) noexcept
{
	if (this != &other)
	{
		Clear();

		head = other.head;
		tail = other.tail;
		size = other.size;
		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
	}

	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::begin()
{
	Iterator iterator(head);
	return iterator;
}

template<typename T>
typename List<T>::Iterator List<T>::end()
{
	Iterator iterator(tail->next);
	return iterator;
}

template<typename T>
List<T>::Iterator::Iterator(Node* node)
	:node(node)
{ }

template<typename T>
typename bool List<T>::Iterator::operator!=(const Iterator& other) const
{
	return node != other.node;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	node = node->next;
	return *this;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator temp(*this);
	node = node->next;
	return temp;
}

template<typename T>
typename T& List<T>::Iterator::operator*()
{
	return node->data;
}

template<typename T>
typename T* List<T>::Iterator::operator->()
{
	return &node->data;
}
