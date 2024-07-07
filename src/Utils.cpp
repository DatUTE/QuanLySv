#include <regex>
#include "Utils.h"

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