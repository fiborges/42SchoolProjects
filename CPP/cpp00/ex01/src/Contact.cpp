#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone = phone;
    this->secret = secret;
}
Contact::Contact(void)
{
    return ;
}
Contact::~Contact(void)
{
    return ;
}

int     Contact::isEmptyFirstName(Contact contact)
{
    if (contact.first_name.empty())
        return (1);
    return (0);
}

void    Contact::printFormattedContactInfo(Contact contact, int i)
{
    if (i == 1)
    {
        if (contact.first_name.size() > 10)
            std::cout << std::string(contact.first_name.begin(), contact.first_name.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact.first_name;
    }
    if (i == 2)
    {
        if (contact.last_name.size() > 10)
            std::cout << std::string(contact.last_name.begin(), contact.last_name.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact.last_name;
    }
    if (i == 3)
    {
        if (contact.nickname.size() > 10)
            std::cout << std::string(contact.nickname.begin(), contact.nickname.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << contact.nickname;
    }
}

void    Contact::displayColorfulContactInfo(Contact contact)
{
    std::cout << std::endl;
    std::cout << GREEN << "First name: "<< RESET << contact.first_name << std::endl;
    std::cout << GREEN << "Last name: " << RESET << contact.last_name << std::endl;
    std::cout << GREEN << "Nickname: " << RESET << contact.nickname << std::endl;
    std::cout << GREEN << "Phone number: " << RESET << contact.phone << std::endl;
    std::cout << GREEN << "Darkest secret: " << RESET << contact.secret << std::endl;
    std::cout << std::endl;
}