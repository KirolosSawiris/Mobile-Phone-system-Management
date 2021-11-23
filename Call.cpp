#include "Call.h"


void Call::set_Duration(int dur)
{
	Duration = dur;
}


int Call::get_Duration()
{
	return Duration;
}

void Call::get_Call(User& A)
{
	string Called_Num;
	cout << "Enter the number you want to call: ";
	cin >> Called_Num;
	cout << "Enter the Duration (in minute): ";
	int dur;
	cin >> dur;
	CallerNumber = A.get_phoneNumber();
	set_CalledPhoneNumber(Called_Num);
	set_Duration(dur);
}

bool Call::is_Call_Valid(User& A, User* Userarr, int NUM)
{
	if (A.get_CreaditVlaue() < Duration * 2)
	{
		cout << "\nyou don't have enough credits!\n";
		return false;
	}
	if (CallerNumber == CalledNumber)
	{
		cout << "\nyou can't call your self!\n";
		return false;
	}
	for (int i = 0; i < NUM; i++)
	{
		if (CalledNumber == Userarr[i].get_phoneNumber())
		{
			int NewValue = A.get_CreaditVlaue() - Duration * 2;
			A.set_CreaditVlaue(NewValue);
			return true;
		}
	}
	cout << "\nNot found number, Try agein!\n";
	return false;
}


Call& Call::operator=(const Call& A)
{
	if (this != &A)
	{
		CallerNumber = A.CallerNumber;
		CalledNumber = A.CalledNumber;
		Duration = A.Duration;
	}
	return *this;
}



void Call::print(User& A)
{
	if (A.get_phoneNumber() == CallerNumber)
	{
		cout << "Outgoing Call to: " << CalledNumber << " Duration: " << Duration << endl;
	}
	if (A.get_phoneNumber() == CalledNumber)
	{
		cout << "Coming Call from: " << CallerNumber << " Duration: " << Duration << endl;
	}
}

Call::Call(const Call& A)
{
	CallerNumber = A.CallerNumber;
	CalledNumber = A.CalledNumber;
	Duration = A.Duration;
}

Call::Call(string caller, string called, int dur)
{
	CallerNumber = caller;
	CalledNumber = called;
	Duration = dur;
}

istream& operator>> (istream& is, Call& A)
{
	is >> A.CallerNumber;
	is >> A.CalledNumber;
	is >> A.Duration;
	return is;
}

ostream& operator<< (ostream& os, Call& A)
{
	os << A.CallerNumber;
	os << endl;
	os << A.CalledNumber;
	os << endl;
	os << A.Duration;
	os << endl;
	return os;
}