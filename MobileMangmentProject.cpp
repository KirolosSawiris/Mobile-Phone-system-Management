#include <iostream>
#include <fstream>
#include"User.h"
#include "Call.h"
#include "Message.h"
using namespace std;

int Count_element(string fileName)   // this functioin count numbers of elements in the call or message file
{
	string line;
	fstream file;
	file.open(fileName.c_str(), ios::in);
	getline(file, line);
	int i;
	for (i = 0; !line.empty(); i++)
	{
		getline(file, line);
	}
	return i / 3;
}

int User_count_element()   // // this functioin count numbers of elements in the user file
{
	string line;
	fstream users_file;
	users_file.open("UsersList.txt", ios::in);
	getline(users_file, line);
	int i;
	for (i = 0; !line.empty(); i++)
	{
		getline(users_file, line);
	}
	users_file.close();
	return i / 5;
}


bool Registerf()          // this funtion save the new users to the file
{
int Users_number = User_count_element();
User* UserNumber = new User[Users_number];
fstream users_file;
users_file.open("UsersList.txt", ios::in);
if (users_file.good())
{
	for (int i = 0; i < Users_number; i++)
	{
		users_file >> UserNumber[i];
	}
}
users_file.close();

string username, password, phonenumber;
int creditValue, EwalletValue;

users_file.open("UsersList.txt", ios::app); // open file in app mode
cout << "Enter your Username: ";
cin >> username;
for (int i = 0; i < Users_number; i++)
{
	if (UserNumber[i].username == username)  // checking if the username already exist
	{
		system("ClS");
		cout << "username already exist. Try another one!\n";
		return false;
	}
}
cout << "Enter your password: ";
cin >> password;
cout << "Enter your phonenumber: ";
cin >> phonenumber;
for (int i = 0; i < Users_number; i++)
{
	if (UserNumber[i].PhoneNumber == phonenumber) // checking if the phone number already exist
	{
		system("ClS");
		cout << "phone number already exist. Try another one!\n";
		return false;
	}
}
cout << "Enter your Ewalletvalue: ";
cin >> EwalletValue;
creditValue = 0;

users_file << username << endl << password << endl << phonenumber << endl;
users_file << creditValue << endl << EwalletValue << endl;
users_file.close();
system("ClS");
cout << "Registration was sucessfull\n";
return true;
}


int main()
{
	int current_User;    // number of the current user int the array
	int CallsNum = Count_element("CallsList.txt");     // number of objects in the calls file
	int Users_number = User_count_element();           // number of objects in the users file
	int MessageNum = Count_element("MessageList.txt"); // number of objects in the Messages file
	User* UserNumber = NULL;
	Call* Callsarr = NULL;
	Message* Messagearr = NULL;
	try 
	{
		UserNumber = new User[Users_number];         // Users Dynamic array
		Callsarr = new Call[CallsNum];               // Calls Dynamic array
		Messagearr = new Message[MessageNum];        // Messages Dynamic array
	}
	catch (bad_alloc& bad)
	{
		cerr << "bad allocation caught: " << bad.what();
	}

	Connection** Connectionarr;       // for Making Dynamic object pointer array
	fstream users_file, calls_file, Message_file;
	int n = 0;
	User userA;
	bool LoginState = false;   // login state which allow user to procced after successfully login
	while (!LoginState)
	{
		do
		{
			cout << "1- Login\n2- Register\n3- Exit\nYour choice number: ";
			cin >> n;
			if (n == 2)
			{
				system("ClS");
				if (Registerf())     // We call registraion function and after that we check if the registration was successful
				{
					Users_number++;
					delete[] UserNumber;
					UserNumber = new User[Users_number];
				}
			}
			else if (n == 1)
			{
				system("ClS");
				users_file.open("UsersList.txt", ios::app);    //we open the file in app mode to create the file if wasn't created
				users_file.close();
				users_file.open("UsersList.txt", ios::in);
				for (int i = 0; i < Users_number; i++)  // reading from the file to users array
				{
					users_file >> UserNumber[i];
				}
				calls_file.open("CallsList.txt", ios::in);  
				for (int i = 0; i < CallsNum ; i++)           // reading from the file to calss array
				{
							calls_file >> Callsarr[i];
				}
				Message_file.open("MessageList.txt", ios::in);  
				for (int i = 0; i < CallsNum; i++)              // reading from the file to Message array
				{
						Message_file >> Messagearr[i];
				}
				Message_file.close();
				calls_file.close();
				users_file.close();
				string username, password;    // the username and the password which we will get from the user to check if they right
				users_file.open("UsersList.txt", ios::in);
				cout << "Enter your Username: ";
				cin >> username;
				bool User_notfound = true;
				for (int i = 0; i < Users_number; i++)
				{
					if (UserNumber[i].get_username() == username) // if we found the username
					{
						cout << "Enter your password: ";
						cin >> password;
						if (password == UserNumber[i].get_password()) // cheking is the password right
						{
							User_notfound = false;
							system("ClS");
							cout << "Welcome " << username << endl;
							current_User = i;
							LoginState = true;
						}
						else
						{
							User_notfound = false;
							system("ClS");
							cout << "wrong password. Try again!\n";
							LoginState = false;

						}
					}
				}
				if (User_notfound)
				{
					system("ClS");
					cout << "user name not found!\n";
					LoginState = false;
				}
				users_file.close();
			}
			else if (n == 3)
			{
				return 0;
			}
			else
			{
				system("ClS");
				cout << "\nInvalid value\n";
			}
		} while (!LoginState);

		while (LoginState)
		{
			cout << "1- View your current information\n2- Edit your current information\n3- Transfare Credit\n4- Top up credits";
			cout << "\n5- Calls and messages sittings\n6- Logout\nEnter your choice number: ";
			cin >> n;
			bool ST = true;
			switch (n)
			{
			case 1:
				system("ClS");
				UserNumber[current_User].print_User();
				break;
			case 2:
				system("CLS");
				UserNumber[current_User].user_edit();
				break;
			case 3:
				system("CLS");
				UserNumber[current_User].transfer_credits(UserNumber, Users_number);
				break;
			case 4:
				system("CLS");
				UserNumber[current_User].topup_credits();
				break;
			case 5:
				system("CLS");
				while (ST == true)
				{
					cout << "1-Make a Call\n2-Send a Message\n3-View Calls and Messages\n4-go back\nChoose: ";
					int O;
					string Called_Num;   // the Called number which we will get from the user to Look for in the array
					Call NewCall;        
					Message NewMessage;
					string content;       // the contern which we will get from the user to store it in the message array
					Call* tempC = NULL;   // temp pointer for Calls
					Message* tempM = NULL;// temp pointer for Messages
					cin >> O;
					switch (O)
					{
					case 1:
						system("CLS");
						NewCall.get_Call(UserNumber[current_User]);
						if (NewCall.is_Call_Valid(UserNumber[current_User], UserNumber, Users_number))
						{	
							CallsNum++;
							Call* tempC = new Call[CallsNum];
							for (int i = 0; i < CallsNum-1; i++)
							{
								tempC[i] = Callsarr[i];
							}
							tempC[CallsNum - 1] = NewCall;
							delete[] Callsarr;
							Callsarr = tempC;
							calls_file.open("CallsList.txt", ios::out);
							for (int i = 0; i < CallsNum; i++)
							{
								calls_file << Callsarr[i];
							}
							calls_file.close();
						}
						break;
					case 2:
						system("CLS");
						NewMessage.get_Message(UserNumber[current_User]);
						if (NewMessage.is_Message_valid(UserNumber[current_User], UserNumber, Users_number))
						{
							MessageNum++;
							Message* tempM = new Message[CallsNum];
							for (int i = 0; i < MessageNum - 1; i++)
							{
								tempM[i] = Messagearr[i];
							}
							tempM[MessageNum - 1] = NewMessage;
							delete[] Messagearr;
							Messagearr = tempM;
							Message_file.open("MessageList.txt", ios::out);
							for (int i = 0; i < MessageNum; i++)
							{
								Message_file << Messagearr[i];
							}
							Message_file.close();
						}
						break;
					case 3:
						system("CLS");
						Connectionarr = new Connection * [MessageNum + CallsNum]; // Dynamic memory of the abstract Calss
						calls_file.open("CallsList.txt", ios::in);
						Message_file.open("MessageList.txt", ios::in);
						for (int i = 0; i < CallsNum; i++)  // storing calls in it
						{
							calls_file >> Callsarr[i];
							Connectionarr[i] = &Callsarr[i];
						}
						for (int i =CallsNum; i < MessageNum+CallsNum; i++)  // storing Messages in it
						{
							Message_file >> Messagearr[i-CallsNum];
							Connectionarr[i] = &Messagearr[i-CallsNum];
						}
						for (int i = 0; i < MessageNum + CallsNum; i++)  // printing Calls and Messages
						{
							Connectionarr[i]->print(UserNumber[current_User]);
						}
						calls_file.close();
						Message_file.close();

						 break;
					case 4:
						ST = false; break;
					default:
						break;
					}
				}
				break;

			case 6:
				system("CLS");
				users_file.open("UsersList.txt", ios::out);  // saving the users after changes in the file
				for (int i = 0; i < Users_number; i++)
				{
					users_file << UserNumber[i];
				}
				users_file.close();
				cout << "You have successfully logged out! \n"; LoginState = false; break;
			default:
				cout << "\nInvalid choice\n";
				break;
			}

		}
	}
	delete[] Callsarr;
	delete[] Messagearr;
	delete[] UserNumber;
	return 0;
}
