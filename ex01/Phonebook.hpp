#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{

private:

    Contact _contacts[8];
    std::string	_strToupper(std::string str) const;
    void _addContact(void);
    bool _validNumber(std::string num) const;
    bool _validateInput(const std::string &input, const std::string &field) const;
    void _searchHeader(void) const;
    void _searchContact(void);

public:

    PhoneBook(void);
    ~PhoneBook(void);

    void welcome(void) const;
    void runCommand(void);
};

#endif