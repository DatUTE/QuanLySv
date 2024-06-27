#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include "Person.h"
#include "Student.h"
#define cls system("cls")
using namespace std;

vector<Student*> list_student;

void NhapThongTin();
void XuatThongTin();
void TimKiemSinhVien();
void XoaThongTin();
void SaveData();
void LoadData();


int check_input(int n);
int check_mssv(string mssv);
//--------------------------------------------------------------
int check_input(int n)
{
	regex re_num("^[0-9]+$");// format digit charactter
	string input;
	int NumberReturn = 0;
	while (1) {
		cout << "Enter your choice: ";
		getline(cin, input);
		if (regex_match(input, re_num) && stoi(input) < n && stoi(input) > 0)
		{
			NumberReturn = stoi(input);
			break;
		}
	}
	return NumberReturn;
}
char checkYorN() { //function to if check input is yes or no
	string s;
	char a;
	bool isvalid = true;
	do {
		cin >> s;
		if ((s.length() > 1)) { //no entering more than 1 charater or numeric character
			isvalid = false;
			cout << "please only enter y/n: ";
			continue;
		}
		else {
			isvalid = true;
		}
		a = s[0];
		if ((a == 'Y') || (a == 'y')) { //convert uppercase in to lowercase
			a = 'y';
		}
		else if ((a == 'n') || (a == 'N')) {
			a = 'n';
		}
		else {
			isvalid = false;
			cout << "please only enter y/n: ";
		}
	} while (!isvalid);
	return a;
}
int check_mssv(string m_mssv)
{
	bool exist = false;
	int m = -1;
	for (int i = 0; i < list_student.size(); i++)
	{
		if (m_mssv.compare(list_student[i]->getMSSV()) == 0)
		{
			exist = true;
			m = i;
			break;
		}
	}
	if (exist)
	{
		cout << "MSSV nay da ton tai " << endl;
		return m;
	}
	else
	{
		cout << "Sinh Vien Moi " << list_student.size() + 1 << endl; ;
		return (list_student.size());
	}
}
int SearchMSSV()
{
	int m = -1;
	int search;
	bool exist = false;
	cout << "Nhap MSSV Ban Can Tim Kiem: ";
	cin >> search;
	cin.ignore(0);
	for (int i = 0; i < list_student.size(); i++)
	{
		int key = stoi(list_student[i]->getMSSV());
		if (search == key)
		{
			exist = true;
			m = i;
			break;
		}
	}
	if (exist) {
		return m;
	}
	else {
		cout << "Khong tim Thay MSSV!" << endl;
		return m;
	}
} 
// ham tach chuoi
const vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}
//ham dang nhap he thong
void SignIn()
{
	const string pass = "hcmute123";
	string Password;
	do
	{
		cout << "Nhap Mat Khau: ";
		getline(cin, Password);
		if (Password == pass)
		{
			cout << "Chao Mung Ban! " << endl;

		}
		else
		{
			cout << "Sai Mat Khau, Moi Ban Nhap Lai!" << endl;
		}
	}while (Password != pass);
	
}
//--------------------------------------------------------------------
int Menu()
{
	cls;
	int choice;
	cout << "QUAN LY SINH VIEN! " << endl;
	cout << "1. Nhap Thong Tin" << endl;
	cout << "2. Xuat Thong Tin" << endl;
	cout << "3. Xoa Sinh Vien" << endl;
	cout << "4. Tim Kiem Sinh Vien" << endl;
	cout << "5. Thoat" << endl;
	choice = check_input(6);
	switch (choice)
	{
	case 1:
		cls;
		cout << "Nhap Thong Tin" << endl;
		NhapThongTin();
		break;
	case 2:
		cls;
		cout << "Xuat Thong Tin" << endl;
		XuatThongTin();
		break;
	case 3:
		cls;
		cout << "Xoa Sinh Vien" << endl;
		XoaThongTin();
		break;
	case 4:
		cls;
		cout << "Tim Sinh Vien" << endl;
		TimKiemSinhVien();
		break;
	case 5:
		cls;
		cout << "GoodBye! " << endl;
		exit(0);
		break;
	default:
		break;
	}
	return 0;
}
void NhapThongTin()
{
	int check;
	char continues = 'n';
	do
	{
		Student* temp_student = new Student;
		cout << "Sinh Vien Thu " << list_student.size() + 1 << endl;
		temp_student->NhapThongTin();
		if (list_student.size() > 0)
		{
			check = check_mssv(temp_student->getMSSV());
			if (check == list_student.size())
			{
				list_student.push_back(temp_student);
			}
			else
			{
				cout << "MSSV Da Ton Tai!" << endl;
				//list_student[check]->copyInfo(temp_student);
			}
		}
		else
		{
			cout << "Sinh vien Dau Tien " << endl;
			list_student.push_back(temp_student);
		}
		cout << "Ban Co Muon Nhap Thong Tin Sinh Vien Thu " << list_student.size() + 1 <<"? y/n:" << endl;
		continues = checkYorN();
		cin.ignore(1);
		cout << endl;
		
	} while (continues == 'y');
	SaveData();
	cls;
	Menu();
}
void XuatThongTin()
{
	cout << "--------THONG TIN SINH VIEN--------" << endl;
	cout << setw(10) << "Name" << setw(10) << "MSSV" << setw(10) << "Age" << setw(10) << "Add" << setw(10) << "Phone" << endl;
	for (int i = 0; i < list_student.size(); i++)
	{
		cout << setw(10) << list_student[i]->getName() << setw(10) << list_student[i]->getMSSV() << setw(10) << list_student[i]->getAge()
			<< setw(10) << list_student[i]->getAdd() << setw(10) << list_student[i]->getPhone() << endl;
	}
	system("pause");
	Menu();
}
void TimKiemSinhVien()
{
	int check;
	check = SearchMSSV();
	
	if (list_student.size() > 0)
	{
		if (check >= 0)
		{
			cout << setw(10) << "Name" << setw(10) << "MSSV" << setw(10) << "Age" << setw(10) << "Add" << setw(10) << "Phone" << endl;
			cout << setw(10) << list_student[check]->getName() << setw(10) << list_student[check]->getMSSV() << setw(10) << list_student[check]->getAge()
				<< setw(10) << list_student[check]->getAdd() << setw(10) << list_student[check]->getPhone() << endl;
		}
	}
	cout << endl;
	system("pause");
	Menu();
}
void XoaThongTin()
{
	int check;
	check = SearchMSSV();
	if (list_student.size() > 0)
	{
		if (check >= 0)
		{
			list_student.erase(list_student.begin() + check);
		}
	}
	system("pause");
	Menu();
}
void SaveData()
{
	fstream file1("Data.txt");
	try
	{
		if (file1.is_open())
		{
			for (int i = 0; i < list_student.size(); i++)
			{
				file1 << list_student[i]->getName() << ";" << list_student[i]->getMSSV() << ";" << list_student[i]->getAge() << ";"
					<< list_student[i]->getAdd() << ";" << list_student[i]->getPhone() << endl;
			}
		}
		throw exception();
	}
	catch (const exception& a)
	{
		cerr << "khong mo duoc file Data.txt" << endl;
	}
	file1.close();
}
void LoadData()
{
	string s;
	string arr[100];
	fstream file2("Data.txt");
	try
	{
		if (file2.is_open())
		{
			while (getline(file2, s))
			{
				vector<string> info;
				Student* temp = new Student;
				stringstream ss(s);
				int i = 0;
				while (ss.good() && i < 13) { //split a long sentence into single strings and assign them into an array
					ss >> arr[i];
				}
				info = explode(arr[0], ';');
				temp->setName(info[0]);
				temp->setMSSV(info[1]);
				temp->setAge(info[2]);
				temp->setAdd(info[3]);
				temp->setPhone(info[4]);
				list_student.push_back(temp);

			}
		}
		else {
			throw exception();
		}
	}
	catch (const exception&)
	{
		cerr << "Khong mo dc file Data.txt" << endl;
	}
	file2.close();
}
//--------------------------------------------------------------------
int main()
{
	LoadData();
	SignIn();
	system("pause");
	cls;
	int selection=0;
	selection = Menu();
	return 0;
}
