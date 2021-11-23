#include "Connection.h"

Connection::Connection(string caller, string called)
{
	CallerNumber = caller;
	CalledNumber = called;
}

void Connection::set_CalledPhoneNumber(string phone)
{
	CalledNumber = phone;
}

void Connection::set_CallerPhoneNumber(string phone)
{
	CallerNumber = phone;
}

string Connection::get_CallerPhoneNumber()
{
	return CalledNumber;
}

string Connection::get_CalledPhoneNumber()
{
	return CalledNumber;
}


