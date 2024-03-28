#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student
{
	string full_name, group;
	float GPA;
public:
	Student();
	Student(string, string, float);
	Student(const Student&);
	~Student();
	string get_full_name();
	void set_full_name(string);
	string get_group();
	void set_group(string);
	float get_GPA();
	void set_GPA(float);
	void show();
};