#include "Phonebook.hpp"
#include "Contact.hpp"

int main( void )
{
    PhoneBook phonebook;
    phonebook.welcome();
    phonebook.runCommand();
    return 0;
}