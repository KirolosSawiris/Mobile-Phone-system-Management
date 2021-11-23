#pragma once
#include "Connection.h"

int Count_element(string fileName);

class Message : public Connection
{
	string Message_content;
public:

	Message(string caller, string called, string message);
	Message(){}
	Message(const Message& A);
	void set_Message_content(string content);
	string get_Message_content();
	Message& operator= (const Message& A);
	void get_Message(User& A);
	bool is_Message_valid(User& A, User* Userarr, int NUM);
	friend istream& operator>> (istream& is, Message& A);
	friend ostream& operator<< (ostream& is, Message& A);
	void print(User& A);
};

