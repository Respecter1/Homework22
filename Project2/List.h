#pragma once
/*
	2. �������� ��������� �������� (�� ��������) ���� ����� List.
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

	// --- Insert method ---(������ �������)

	void PushBack(const int& value);
	void PushFront(const int& value);

	// --- Remove methods ---(������ �� ���������)

	void PopBack();//�������� � ����
	void PopFront();//�������� � ������� 
	void Remove(const int& value);// �������� ����� ���������� ����� ��������, ���� ������ �� � ��� ����� � ����� ���������. ���� � ��� �������.
	void Clear();//��� �����

	// --- Find methods ---

	bool Find(const int& value) const;// ��� ������, � ������ �� ������� ���������� ��� ����� ������. � ������ ��������� [try] ���� �������� [false] ���� �  

	// --- �heck size methods ---(������ �� ���������� �����)

	bool IsEmpty() const;//�������� �� ������ ��������� ������ 
	size_t Size() const;//������� ����� ������ ������

	// --- Assigment operator ---

	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;

	// --- Index operator ---
	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	// --- Extra methods ---

	void Shows() const;

private:

	void Copy(const List& other);//����� ����� ������(��� ����� ������� ��� ��������� ���������� ����

	struct Node
	{
		int data;
		Node* next;
	};

	Node* head; //�������� �� ������ 

};

