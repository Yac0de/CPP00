#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook(void)
{
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void PhoneBook::welcome(void) const
{
    std::cout << std::endl << "WELCOME TO YOUR AWESOME PHONEBOOK !" << std::endl;
    std::cout << "---------------USAGE----------------" << std::endl;
    std::cout << "ADD => Register a new contact" << std::endl;
    std::cout << "SEARCH => Displays the requested contact" << std::endl;
    std::cout << "EXIT => The program quits and contacts are lost forever!" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    return;
}

std::string PhoneBook::_strToupper(std::string str) const
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
    return (str);
}

void PhoneBook::runCommand()
{
    std::string cmd = "";

    while (!std::cin.eof() && _strToupper(cmd) != "EXIT")
    {
        std::cout << std::endl << "Enter a command: ";
        std::getline(std::cin, cmd);

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "An error occurred while reading the command. Please try again." << std::endl;
            continue;
        }
        if (_strToupper(cmd) == "ADD")
            _addContact();
        else if (_strToupper(cmd) == "SEARCH")
            _searchContact();
        else if (_strToupper(cmd) != "EXIT")
            std::cout << std::endl << "Invalid command!" << std::endl;
    }
    return;
}

bool PhoneBook::_validNumber(std::string num) const
{
    if (num.length() < 6 || num.length() > 15)
    {
        std::cout << "Invalid phone number length" << std::endl;
        return false;
    }

    size_t start = 0;
    if (num[0] == '+')
        start = 1;

    for (size_t i = start; i < num.length(); i++)
    {
        if (!isdigit(num[i]))
        {
            std::cout << "Invalid phone number character" << std::endl;
            return false;
        }
    }
    return true;
}

bool PhoneBook::_validateInput(const std::string &input, const std::string &field) const
{
    if (input.empty())
    {
        std::cerr << field << " cannot be empty." << std::endl;
        return false;
    }
    if (input.length() > 50)
    {
        std::cerr << field << " is too long. Max length is 50 characters." << std::endl;
        return false;
    }
    return true;
}

void PhoneBook::_addContact(void)
{
    static int i = 0;
    Contact contact;

    std::string firstname, lastname, nickname, phonenumber, darkestsecret;

    std::cout << std::endl << "Enter the first name: ";
    std::getline(std::cin, firstname);
    if (!_validateInput(firstname, "First name")) return;
    contact.setFirstName(firstname);

    std::cout << "Enter the last name: ";
    std::getline(std::cin, lastname);
    if (!_validateInput(lastname, "Last name")) return;
    contact.setLastName(lastname);

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, nickname);
    if (!_validateInput(nickname, "Nickname")) return;
    contact.setNickname(nickname);

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, phonenumber);
    if (!_validNumber(phonenumber)) return;
    contact.setPhoneNumber(phonenumber);

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, darkestsecret);
    if (!_validateInput(darkestsecret, "Darkest secret")) return;
    contact.setDarkestSecret(darkestsecret);

    _contacts[i % 8] = contact;
    i++;
    std::cout << "Contact added successfully!" << std::endl; 
    return;
}

void PhoneBook::_searchHeader(void) const
{
    std::cout << std::endl << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;
}

void PhoneBook::_searchContact(void)
{
    int i;

    _searchHeader();
    for(i = 0; i < 8; i++)
        _contacts[i].displayContactInArray(i);
    std::cout << std::endl << "Enter the index of the contact you want to display: ";
    std::cin >> i;
    std::cout << std::endl;

    if (std::cin.fail() || i < 0 || i > 7)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index" << std::endl;
        return;
    }

    _contacts[i].displayContactInfos(i);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}
