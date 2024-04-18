#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact
{
private:
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _phonenumber;
    std::string _darkestsecret;

    std::string _truncateString(const std::string &str) const;

public:
    Contact(void);
    ~Contact(void);

    void setFirstName(const std::string &firstname);
    std::string getFirstName() const;

    void setLastName(const std::string &lastname);
    std::string getLastName() const;

    void setNickname(const std::string &nickname);
    std::string getNickname() const;

    void setPhoneNumber(const std::string &phonenumber);
    std::string getPhoneNumber() const;

    void setDarkestSecret(const std::string &darkestsecret);
    std::string getDarkestSecret() const;

    void displayContactInArray(int i) const;
    void displayContactInfos(int i) const;
};

#endif
