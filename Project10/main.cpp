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



