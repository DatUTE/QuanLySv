
#include "Person.h"

Person::Person()
{
	
};
Person::~Person() {

};
string Person::getName()
{
	return _name;
}
string Person::getAdd()
{
	return _add;
}
string Person::getAge()
{
	return _age;
}
string Person::getPhone()
{
	return _phone;
}
void Person::setName(string name)
{
	_name = name;
}
void Person::setAdd(string add)
{
	_add = add;
}
void Person::setAge(string age) {
	_age = age;
}
void Person::setPhone(string phone)
{
	_phone = phone;
}

