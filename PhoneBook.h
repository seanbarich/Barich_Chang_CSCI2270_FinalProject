#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <sstream>
#include <iostream>

struct Contact {
    std::string number;
    std::string name;
    std::string email;
    int search;
    Contact *parent;
    Contact *left;
    Contact *right;

    Contact(){};

    Contact(std::string in_number,std::string in_name, std::string in_email)
    {
        number = in_number;
        name = in_name;
        email = in_email;
        search = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    void SearchPhoneBook(std::string name);
    void addContact(std::string name, std::string number, std::string email);
    void deleteContact(std::string name);
    void printPhoneBook();
    void saveContacts();
    void Favorites();

private:
    PhoneBook *root;
    PhoneBook* search(std::string name, PhoneBook *node);
};
#endif // PHONEBOOK_H
