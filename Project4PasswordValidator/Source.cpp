#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

enum PWSIZE //Array Size
{
	PASSWORD_SIZE = 20
};

//Function Prototype
int testNum(char[]);
int re_enter(char[]);

int main()
{
	char password[PASSWORD_SIZE]; //To hold password
	int length;

	length = strlen(password);
	while (1)
	{
		//Get the password.
		do {
			cout << "Please enter a password with at least 6 characters.\n";
			cout << "Enter your password: ";
			cin.getline(password, PASSWORD_SIZE);
			length = strlen(password);
		} while (length < 6);

		//Call function.
		if (testNum(password))
			continue;           //if return 1 pass below
		if (re_enter(password))
			continue;

		break;
	}
	return 0;
}

int testNum(char pswd[])
{
	int count;
	bool upper_flag = 0, lower_flag = 0, digit_flag = 0;
	for (count = 0; count < strlen(pswd); count++)    //don't need to Size use strlen
	{

		if (isupper(pswd[count]))
			upper_flag = 1;
		else if (islower(pswd[count]))
			lower_flag = 1;
		else if (isdigit(pswd[count]))
			digit_flag = 1;
	}
	if (!upper_flag)
	{
		cout << "The password does not contain an uppercase letter.\n";
	}

	if (!lower_flag)
	{
		cout << "The password does not contain a lowercase letter.\n";
	}
	if (!digit_flag)
	{
		cout << "The password does not contain a digit.\n";
	}
	if (upper_flag && lower_flag && digit_flag)
		return 0;   //if all pass
	else
		return 1;
}

int re_enter(char  passwd[])
{
	char compare_password[PASSWORD_SIZE] = { 0, };
	cout << "Re Enter Your password" << endl;
	cin.getline(compare_password, PASSWORD_SIZE);
	if (strcmp(passwd, compare_password))
	{
		cout << "Password Not Match" << endl;
		return 1;
	}
	return 0;
}