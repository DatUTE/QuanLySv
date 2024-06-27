#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include<regex>
#include"Person.h"

class Student : public Person
{
public:
	Student();
	~Student();

	void NhapThongTin();
	void XuatThongTin();

	string getMSSV();
	void setMSSV(string ms);
	void copyInfo(Student* st);
private:
	string _mssv;
};
#endif // STUDENT_H
