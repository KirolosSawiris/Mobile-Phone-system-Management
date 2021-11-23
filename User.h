#pragma once
#include <iostream>
#include <fstream>
#include<stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <new>

using namespace std;
int User_count_element();

class User
{
private:
	string username;
	string Password;
	string PhoneNumber;
	int EwalletValue;
	int CreditValue;

public:
	User(string name, string pass, string phone, int Ewallet, int Credit);
	User(){}
	User(const User& b);
	void set_username(string name);
	void set_password(string pass);
	void set_phoneNumber(string phone);
	void set_EwalletValue(int Ewallet);
	void set_CreaditVlaue(int Creadit);
	string get_username();
	string get_password();
	string get_phoneNumber();
	int get_EwalletValue();
	int get_CreaditVlaue();
	bool topup_credits();
	bool transfer_credits(User* Userarr, int N);
	void print_User() const;
	void user_edit();

	friend bool Registerf();
	friend istream& operator>> (istream& is, User& A);
	friend ostream& operator<< (ostream& is, User& A);
};


	
