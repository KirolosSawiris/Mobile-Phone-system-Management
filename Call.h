#pragma once
#include "User.h"
#include "Connection.h"

int Count_element(string fileName);

class Call : public Connection
{
	int Duration;
public:
	Call (string caller, string called, int dur);
	Call() {};
	Call(const Call& A);
	void set_Duration(int dur);
	int get_Duration();
	void get_Call(User& A);
	bool is_Call_Valid(User& A, User* Userarr, int NUM);
	friend istream& operator>> (istream& is, Call& A);
	friend ostream& operator<< (ostream& is, Call& A);
	Call& operator= (const Call& A);
	void print(User& A);
};

