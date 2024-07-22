/*
		11. ����� ��� �� ������ 10 ����� �����, ��� ��� ����������� ����� ��� ������� �������� ���������������� ��'��� �������.
*/


#include "SchoolClass.h"
#include <list>


int main()
{
    SchoolClass myClass;

    // ������ �������� �� �����
    myClass.AddStudent(Student("Harry", 16));
    myClass.AddStudent(Student("Sally", 15));
    myClass.AddStudent(Student("Bill", 17));
    myClass.AddStudent(Student("Peter", 16));

    // ³��������� ������ ��������
    cout << "Initial list of students:\n";
    myClass.Show();

    // �������� �� ������� �������� �� ���� ��
    myClass.IncreaseAgeOfAllStudents();

    // ³��������� ��������� ������ ��������
    cout << "List of students after increasing age:\n";
    myClass.Show();

    return 0;
}