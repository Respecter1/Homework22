#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
	Student();
	Student(const string& name, const int age);
	Student(const Student& rhs);
	~Student();

	void SetName(const string& name);
	string GetName() const;
	void SetAge(const int age);
	int GetAge() const;
	
	Student& operator=(const Student& rhs);


	Student& operator+=(int increment) {
		itsAge += increment;
		return *this;
	}
private:
	string itsName;
	int itsAge;
};

Student::Student()
	: itsName("New Student"), itsAge(16)
{
}

Student::Student(const string& name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student& rhs) : itsName(rhs.GetName()),
itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string& name)
{
	itsName = name;
}

string Student::GetName() const
{
	return itsName;
}

void Student::SetAge(const int age)
{
	itsAge = age;
}

int Student::GetAge() const
{
	return itsAge;
}

Student& Student::operator=(const Student& rhs)
{
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}

ostream& operator<<(ostream& os, const Student& rhs)
{
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}

template <class T>
void ShowVector(const vector<T>& v); // Відображає властивості вектора

typedef vector<Student> SchoolClass;



//
// Відображає властивості вектора
//
template <class T>
void ShowVector(const vector<T>& v)
{
	cout << "max_size() = " << v.max_size();
	cout << "\tsize() = " << v.size();
	cout << "\tcapacity() = " << v.capacity();
	cout << "\t " << (v.empty() ? "empty" : "not empty");
	cout << "\n";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
	cout << endl;
}
