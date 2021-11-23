#include "User.h"


User::User(string name, string pass, string phone, int Ewallet = 0, int Credit = 0)
{
	username = name;
	Password = pass;
	PhoneNumber = phone;
	EwalletValue = Ewallet;
	CreditValue = Credit;
}
User::User(const User& b)
{
	username = b.username;
	Password = b.Password ;
	PhoneNumber = b.PhoneNumber;
	EwalletValue = b.EwalletValue;
	CreditValue = b.CreditValue;
}


void User::set_username(string name)
{
	username = name;
}
void User::set_password(string pass)
{
	Password = pass;
}
void User::set_phoneNumber(string phone)
{
	PhoneNumber = phone;
}
void User::set_EwalletValue(int Ewallet)
{
	EwalletValue = Ewallet;
}
void User::set_CreaditVlaue(int Creadit)
{
	CreditValue = Creadit;
}
string User::get_username()
{
	return username;
}
string User::get_password()
{
	return Password;
}
string  User::get_phoneNumber()
{
	return PhoneNumber;
}
int User::get_EwalletValue()
{
	return EwalletValue;
}
int User::get_CreaditVlaue()
{
	return CreditValue;
}

bool User::topup_credits()
{
	system("ClS");
	cout << "\n 1$ give 10 credits, Enter number of dollers that you want to exchange: ";
	int n;
	cin >> n;
	if (EwalletValue < n)
	{
		system("ClS");
		cout << "\nsorry, you don't have that ammount\n";
		return false;
	}
	else
	{
		CreditValue = CreditValue + n * 10;
		EwalletValue = EwalletValue - n;
		return true;
	}

}

bool User::transfer_credits(User* Userarr, int N)
{
	system("ClS");
	cout << "Enter number of credits that you want to transfer: ";
	int n;
	cin >> n;
	if (CreditValue < n)
	{
		system("ClS");
		cout << "\nsorry, you don't have enough credits\n";
		return false;
	}
	cout << "\nEnter the phoneNumber  you want to transfer this ammount to: ";
	string t_Num;
	cin >> t_Num;
	for (int i = 0; i < N; i++)
	{
		if (t_Num == Userarr[i].get_phoneNumber())
		{
			CreditValue = CreditValue - n;
			Userarr[i].CreditValue = Userarr[i].CreditValue + n;
			system("ClS");
			cout << "\ntransaction succeeded\n";
			return true;
		}
	}
	cout << "\nNot found number, Try agein!\n";
	return false;
}

void User::print_User() const
{
	cout << "User name : " << username << endl;
	cout << "password : " << Password << endl;
	cout << "phone number : " << PhoneNumber << endl;
	cout << "Credit Value : " << CreditValue << endl;
	cout << "E wallet Value : " << EwalletValue << endl << endl;
}

void User::user_edit()
{
	cout << "\n1-password\n2-E-wallet Value\n3-go back\n Enter your choice to edit: ";
	int n;
	cin >> n;
	string pass = Password;
	int v = EwalletValue;
	switch (n)
	{
	case 1:
		cout << "\nEnter new password: ";
		cin >> pass;
		this->set_password(pass);
		break;
	case 2:
		cout << "\nEnter new E-wallet Value: ";
		cin >> v;
		this->set_EwalletValue(v);
		break;
	default:
		break;
	}
}

istream& operator>> (istream& is, User& A)
{
	is >> A.username;
	is >> A.Password;
	is >> A.PhoneNumber;
	is >> A.CreditValue;
	is >> A.EwalletValue;
	return is;
}

ostream& operator<< (ostream& os,User& A)
{
	os << A.username;
	os << endl;
	os << A.Password;
	os << endl;
	os << A.PhoneNumber;
	os << endl;
	os << A.CreditValue;
	os << endl;
	os << A.EwalletValue;
	os << endl;
	return os;
}

