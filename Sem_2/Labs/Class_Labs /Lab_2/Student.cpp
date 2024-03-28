#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
Student::Student()
{
	full_name = "";
	group = "";
	GPA = 0;
	cout << "����������� ��� ���������� ��� �������: " << this << "\n";
}
Student::Student(string N, string K, float S)
{
	full_name = N;
	group = K;
	GPA = S;
	cout << "����������� � ����������� ��� �������: " << this << "\n";
}
Student::Student(const Student &t)
{
	full_name = t.full_name;
	group = t.group;
	GPA = t.GPA;
	cout << "����������� ����������� ��� �������: " << this << "\n";
}
Student::~Student()
{
	cout << "���������� ��� �������: " << this << "\n";
}
string Student::get_full_name()
{
	return full_name;
}
string Student::get_group()
{
	return group;
}
float Student::get_GPA() const
{
	return GPA;
}
void Student::set_full_name(string N)
{
	full_name = N;
}
void Student::set_group(string K)
{
	group = K;
}
void Student::set_GPA(float S)
{
	GPA = S;
}
void Student::show() const
{
	cout << "���: " << full_name
		 << "\n������: " << group
	     << "\n������� ����: " << GPA << "\n\n";
}

