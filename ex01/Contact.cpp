#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
    return;
}

Contact::~Contact(void)
{
    return;
}

std::string Contact::_truncateString(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

std::string Contact::getFirstName() const { return _firstname; }
std::string Contact::getLastName() const { return _lastname; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phonenumber; }
std::string Contact::getDarkestSecret() const { return _darkestsecret; }

void Contact::setFirstName(const std::string &firstname) { _firstname = firstname; }
void Contact::setLastName(const std::string &lastname) { _lastname = lastname; }
void Contact::setNickname(const std::string &nickname) { _nickname = nickname; }
void Contact::setPhoneNumber(const std::string &phonenumber) { _phonenumber = phonenumber; }
void Contact::setDarkestSecret(const std::string &darkestsecret) { _darkestsecret = darkestsecret; }


void Contact::displayContactInArray(int i) const
{
    std::cout << "|" << std::setw(10) << i << "|";
    std::cout << std::setw(10) << _truncateString(getFirstName()) << "|";
    std::cout << std::setw(10) << _truncateString(getLastName()) << "|";
    std::cout << std::setw(10) << _truncateString(getNickname()) << "|";
    std::cout << std::endl;
}

void Contact::displayContactInfos(int i) const
{
    if(getLastName().empty())
    {
        std::cout   << "contact not yet assigned" << std::endl;
        return;
    }
    std::cout   << "index: " << i << std::endl
                << "first name: " << getFirstName() << std::endl
                << "last name: " << getLastName() << std::endl
                << "nickname: " << getNickname() << std::endl
                << "phone number: " << getPhoneNumber() << std::endl
                << "darkest secret: " << getDarkestSecret() << std::endl;
    return;
}
