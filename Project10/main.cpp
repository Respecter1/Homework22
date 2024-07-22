/*
		10. Напишіть виконання класу SchoolClass, показаного у лістингу 19.8 як списку
		. Для додавання до списку чотирьох студентів використовуйте функцію push_back()
		. Потім пройдіться по отриманому списку та збільште вік кожного студента на один рік.
*/

#include "SchoolClass.h"
#include <list>


int main()
{



	std::list<Student> MyClass;
	MyClass.push_back(Student());
	MyClass.push_back(Student("Sally", 15));
	MyClass.push_back(Student("Bill", 17));
	MyClass.push_back(Student("Peter", 16));

	for (auto it = MyClass.begin(); it != MyClass.end(); ++it) {
		*it += 1;  // Збільшуємо вік на 1
		std::cout << *it << " ";
	}

	return 0;
}















/*

////
EmptyClass;:
max_size() = 576460752303423487 size() = 0      capacity() = 0   empty

GrowingClass(3) :
	max_size() = 576460752303423487 size() = 3      capacity() = 3   not empty
	New Student is 16 years old
	New Student is 16 years old
	New Student is 16 years old

	GrowingClass(3) after assigning students :
	max_size() = 576460752303423487 size() = 3      capacity() = 3   not empty
	New Student is 16 years old
	Sally is 15 years old
	Bill is 17 years old

	GrowingClass() after aded 4ht student :
	max_size() = 576460752303423487 size() = 4      capacity() = 6   not empty
	New Student is 16 years old
	Sally is 15 years old
	Bill is 17 years old
	Peter is 16 years old

	GrowingClass() after Set :
	max_size() = 576460752303423487 size() = 4      capacity() = 6   not empty
	Harry is 18 years old
	Sally is 15 years old
	Bill is 17 years old
	Peter is 16 years old


*/