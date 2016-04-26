#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "PhoneBook.h"

using namespace std;

int main()
{
        PhoneBook *pNode = new PhoneBook;
        int input = 1;
        while(input != 7 && input < 7 && input > 0){
        cout << "======Main Menu======" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Print PhoneBook" << endl;
        cout << "4. Search PhoneBook" << endl;
        cout << "5. Print Recent Contacts" << endl;
        cout << "6. Edit Contact" << endl;
        cout << "7. Quit" << endl;


        cout << "Enter Choice:";
        cin >> input;

        if(input==1)
        {
            cout << "Enter name:" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter number:" << endl;
            string number;
            getline(cin, number);
            cout << "Enter email:" << endl;
            string email;
            getline(cin, email);
            pNode->addContact(name, number, email, 0, 0);
        }

        if(input==2)
        {
            cout << "Enter name:" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            pNode->deleteContact(name);
        }

        if(input==3)
        {
            pNode->printPhoneBook();
        }

        if(input==4)
        {
            pNode->printPhoneBook();
        }

        if(input==5)
        {
            pNode->Recent();
        }

        if(input==6)
        {
			cin.ignore();
            cout << "Enter Original Name:" << endl;
            string name1;
            getline(cin, name1);
            cout << "Enter New Name:" << endl;
            string name2;
            getline(cin, name2);
            cout << "Enter Number:" << endl;
            string number;
            getline(cin, number);
            cout << "Enter Email:" << endl;
            string email;
            getline(cin, email);
            pNode->editContact(name1, name2, number, email);
        }

        if(input==7)
        {
            cout<<"Goodbye"<<endl;
        }
	}
}
