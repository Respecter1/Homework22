#include "List.h"

#include <iostream>


List::List()
	:head(nullptr)
{}

List::List(const List& other)
	:List()
{
	Copy(other);
}

List::List(List&& other) noexcept
	:head(other.head)
{
	other.head = nullptr;
}

List::~List()
{
	Clear();
}

void List::PushBack(const int& value)
{
	if (head == nullptr)
	{
		head = new Node{ value,nullptr };
	}
	else
	{
		Node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node{ value, nullptr };
	}
}

void List::PushFront(const int& value)
{
	if (head == nullptr)
	{
		head = new Node{ value,nullptr };
	}
	else
	{
		Node* newNode = new Node{ value, head };
		head = newNode;
	}
}

void List::PopBack()
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
		Node* previous = head;//попередній
		Node* current = head->next;//данний

		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}

		delete current;
		previous->next = nullptr;
	}
}

void List::PopFront()
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
}

void List::Remove(const int& value)
{
	Node* previous = nullptr;
	Node* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			if (previous == nullptr)//коли previous складається лише с 1 елемента
			{
				head = head->next;
			}
			else
			{
				previous->next = current->next;
			}

			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}
}

void List::Clear()
{
	while (head != nullptr)
	{
		Node* current = head;
		head = head->next;

		delete current;
	}
}

bool List::Find(const int& value) const
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

bool List::IsEmpty() const
{
	return head == nullptr;
}

size_t List::Size() const
{
	size_t size = 0;

	Node* current = head;
	while (current != nullptr)
	{
		size++;
		current = current->next;
	}

	return size;
}

List& List::operator=(const List& other)
{
	if (this != &other)
	{
		Clear();
		Copy(other);
	}

	return *this;
}

List& List::operator=(List&& other) noexcept
{
	if (this != &other)
	{
		Clear();

		head = other.head;
		other.head = nullptr;
	}

	return *this;
}

int& List::operator[](size_t index)
{
	if (index >= Size())
	{
		throw std::out_of_range("Incorred index int List::operator[]");
	}

	Node* current = head;

	for (size_t i = 0; i < index; i++)
	{
		current = current->next;
	}
}

const int& List::operator[](size_t index) const
{
	if (index >= Size())
	{
		throw std::out_of_range("Incorred index int List::operator[]");
	}

	Node* current = head;

	for (size_t i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current->data;
}

void List::Shows() const
{
	if (head == nullptr)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}

		std::cout << std::endl;
	}
}

void List::Copy(const List& other)
{
	if (other.head == nullptr)
	{
		head = nullptr;

	}
	else
	{
		head = new Node{ other.head->data,nullptr };//указує на новий вузов

		Node* current = head;
		Node* otherCurrent = other.head;

		while (otherCurrent->next != nullptr)
		{
			current->next = new Node{ otherCurrent->next->data,nullptr };

			current = current->next;
			otherCurrent = otherCurrent->next;
		}
	}




}
