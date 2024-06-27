#include "Student.h"

Student::Student()
{
	_mssv = " ";
}
Student::~Student()
{

}
string Student::getMSSV()
{
	return _mssv;
}
void Student::setMSSV(string ms)
{
	_mssv = ms;
}
void Student::NhapThongTin()
{
	regex re_name("^([a-zA-Z]){2,20}$");
	regex r_mssv("^[0-9]{8}$");			// mssv gom 8 chu so
	string _input;
	while (1)
	{
		cout << "Nhap Ten Sinh Vien: " ;
		getline(cin, _input);
		setName(_input);
		cin.ignore(0);
		if (!regex_match(getName(), re_name))
		{
			cout << "Ten Khong Duoc La Ky Tu Dac Biet!" << endl;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		cout << "Nhap MSSV: ";
		getline(cin, _input);
		setMSSV(_input);
		cin.ignore(0);
		if (!regex_match(getMSSV(), r_mssv))
		{
			cout << "MSSV gom 8 chu so!" << endl;
		}
		else
		{
			break;
		}
		
	}
	cout << "Nhap Tuoi: ";
	getline(cin, _input);
	setAge(_input);
	cin.ignore(0);

	cout << "So Dien Thoai: ";
	cin >> _input;
	cin.ignore(1);
	setPhone(_input);

	cout << "Nhap dia chi: ";
	getline(cin, _input);
	cin.ignore(0);
	setAdd(_input);
}
void Student::XuatThongTin()
{
	cout << "Thong Tin Sinh Vien" << endl;
	cout << setw(5) << getName() << setw(10) //<<getMSSV() 
		<< setw(10) << getAge() << setw(10) << getAdd() << setw(10) << getPhone() << endl;
}
void Student::copyInfo(Student* st)
{
	setName(st->getName());
	setMSSV(st->getMSSV());
	setAge(st->getAge());
	setAdd(st->getAdd());
	setPhone(st->getPhone());
}
