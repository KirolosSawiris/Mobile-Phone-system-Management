#include "Message.h"

Message::Message(string caller, string called, string message)
{
	CallerNumber = caller;
	CalledNumber = called;
	Message_content = message;
}

Message::Message(const Message& A)
{
	CallerNumber = A.CallerNumber;
	CalledNumber = A.CalledNumber;
	Message_content = A.Message_content;
}

void Message::set_Message_content(string content)
{
	Message_content = content;
}

string Message::get_Message_content()
{
	return Message_content;
}

Message& Message::operator=(const Message& A)
{
	if (this != &A)
	{
		CallerNumber = A.CallerNumber;
		CalledNumber = A.CalledNumber;
		Message_content = A.Message_content;
	}
	return *this;
}

void  Message::get_Message(User& A)
{
	string Called_Num;
	string content;
	cout << "Enter the number you want to Message: ";
	cin >> Called_Num;
	cout << "Enter the Content: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, content);
	replace(content.begin(), content.end(), ' ', '+');
	CallerNumber = A.get_phoneNumber();
	CalledNumber = Called_Num;
	Message_content = content;
}

bool Message::is_Message_valid(User& A, User* Userarr, int NUM)
{
	if (A.get_CreaditVlaue() < 10)
	{
		cout << "\nyou don't have enough credits!\n";
		return false;
	}
	if (CalledNumber == CallerNumber)
	{
		cout << "\nyou can't Message your self!\n";
		return false;
	}
	for (int i = 0; i < NUM; i++)
	{
		if (CalledNumber == Userarr[i].get_phoneNumber())
		{
			int NewValue = A.get_CreaditVlaue() - 10;
			A.set_CreaditVlaue(NewValue);
			return true;
		}
	}
	cout << "\nNot found number, Try agein!\n";
	return false;
}


void Message::print(User& A)
{
	replace(Message_content.begin(), Message_content.end(), '+', ' ');
	if (A.get_phoneNumber() == CallerNumber)
	{
		cout << "Outgoing Message to: " << CalledNumber << " Content: " << Message_content << endl;
	}
	if (A.get_phoneNumber() == CalledNumber)
	{
		cout << "Coming Message from: " << CallerNumber << " Content: " << Message_content << endl;
	}
	replace(Message_content.begin(), Message_content.end(), ' ', '+');
}

istream& operator>> (istream& is, Message& A)
{
	is >> A.CallerNumber;
	is >> A.CalledNumber;
	is >> A.Message_content;
	return is;
}

ostream& operator<< (ostream& os, Message& A)
{
	os << A.CallerNumber;
	os << endl;
	os << A.CalledNumber;
	os << endl;
	os << A.Message_content;
	os << endl;
	return os;
}
