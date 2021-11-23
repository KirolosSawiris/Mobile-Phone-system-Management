#pragma once
#include"User.h"

class Connection
{
protected:
	string CallerNumber;
	string CalledNumber;

public:
	Connection(string caller, string called);
	Connection (){}
	void set_CalledPhoneNumber(string phone);
	void set_CallerPhoneNumber(string phone);
	string get_CallerPhoneNumber();
	string get_CalledPhoneNumber();
	virtual void print(User& A) = 0;

};

