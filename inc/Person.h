#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Person
{
public:
	Person();
	~Person();
	virtual void NhapThongTin() =0;
	virtual void XuatThongTin()=0;
	string getName();
	string getAdd();
	string getAge();
	string getPhone();
	void setName(string name);
	void setAdd(string add);
	void setAge(string age);
	void setPhone(string phone);

private:
	string _name;
	string _add;
	string _age;
	string _phone;
};

