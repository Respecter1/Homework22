#pragma once
/*
	2. Напишіть виконання звичайної (не шаблонної) версії класу List.
*/

#pragma once

class List
{
public:
	// --- Constructors ---
	List();
	List(const List& other);
	List(List&& other) noexcept;

	// --- Destructor ---

	~List();

	// --- Insert method ---(методи вставки)

	void PushBack(const int& value);
	void PushFront(const int& value);

	// --- Remove methods ---(методи які видаляють)

	void PopBack();//видалити з кінця
	void PopFront();//видалити з початку 
	void Remove(const int& value);// видаляти вузов вставляючи певне значення, буде шукати чи є цей вузов с таким значенням. Якщо є тоді видаляє.
	void Clear();//все очищає

	// --- Find methods ---

	bool Find(const int& value) const;// для пошуку, в душках ми указуємо значеннння яке треба знайти. І будемо повертати [try] якщо зннайшло [false] якщо ні  

	// --- Сheck size methods ---(методи які перевіряють розмір)

	bool IsEmpty() const;//перевіряє чи список являється пустий 
	size_t Size() const;//повертає розмір нашого списку

	// --- Assigment operator ---

	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;

	// --- Index operator ---
	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	// --- Extra methods ---

	void Shows() const;

private:

	void Copy(const List& other);//копіює інший список(цей метод зроблен для уникнення дублювання коду

	struct Node
	{
		int data;
		Node* next;
	};

	Node* head; //вказівник на голову 

};

