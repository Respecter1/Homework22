/*
		11. Змініть код із вправи 10 таким чином, щоб для відображення даних про кожного студента використовувався об'єкт функції.
*/


#include "SchoolClass.h"
#include <list>


int main()
{
    SchoolClass myClass;

    // Додаємо студентів до класу
    myClass.AddStudent(Student("Harry", 16));
    myClass.AddStudent(Student("Sally", 15));
    myClass.AddStudent(Student("Bill", 17));
    myClass.AddStudent(Student("Peter", 16));

    // Відображаємо список студентів
    cout << "Initial list of students:\n";
    myClass.Show();

    // Збільшуємо вік кожного студента на один рік
    myClass.IncreaseAgeOfAllStudents();

    // Відображаємо оновлений список студентів
    cout << "List of students after increasing age:\n";
    myClass.Show();

    return 0;
}