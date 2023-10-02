#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{   
    i = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int isSingleDigitInRange(std::string s, int i)
{
    if (s.size() != 1)
        return (0);
    if (48 <= s[0] && s[0] <= 48 + i)
        return (1);
    return (0);
}

std::string  getNonEmptyInputWithPrompt(std::string msg)
{
    std::string userInput;
    
    std::cout << msg;
    while (true)
    {
        std::getline(std::cin, userInput);
        if (std::cin.eof())
        {
            std::cout << RED << "EXIT PROGRAM" << RESET << std::endl;
            exit(0);
        }
        userInput.erase(0, userInput.find_first_not_of(" \t\v\f\r"));
        while (isspace(userInput[userInput.length() - 1]))
            userInput.erase(userInput.find_last_not_of(" \t\v\r\f") + 1, userInput[userInput.length() - 1]);
        if (userInput.empty())
        {
            std::cout << std::endl;
            std::cout << RED << "Empty field not valid! Please, try again." << RESET << std::endl << msg;
            std::cout << std::endl;
        }
        else
            break ;
    }
    return (userInput);
}

void    PhoneBook::addContactAtIndex()
{
    Contact new_contact(getNonEmptyInputWithPrompt("\033[34mFirst name: \033[0m"), getNonEmptyInputWithPrompt("\033[34mLast name: \033[0m"),
                        getNonEmptyInputWithPrompt("\033[34mNickname: \033[0m"),getNonEmptyInputWithPrompt("\033[34mPhone number: \033[0m"),
                        getNonEmptyInputWithPrompt("\033[34mDarkest secret: \033[0m"));                   
    contacts[i++ % 8] = new_contact;
}

int PhoneBook::countNonEmptyContacts(PhoneBook phone)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (phone.contacts[i].isEmptyFirstName(phone.contacts[i]))
            break ;
        i++;
    }
    return (i);
}
/*
PhoneBook PhoneBook::shiftContactsBack(PhoneBook phone)
{
   int i;
    
    i = 0;
     while (i < 7)
    {
        phone.contacts[i] = phone.contacts[i + 1];
        i++;
    }
    return (phone);
}
*/

void        PhoneBook::showContacts(PhoneBook phone)
{
    int contactIndex;
    int lastValidIndex;
    std::string chosenIndex;

    contactIndex = 0;
    if (phone.contacts[0].isEmptyFirstName(phone.contacts[0]))
    {
        std::cout << std::endl;
        std::cout << RED << "Your Phonebook is empty!!" << RESET << std::endl;
        std::cout << std::endl;
        return ;
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "| <3  <3  <3  <3  <3  <3  <3  <3  <3  <3  <3|" << RESET << std::endl;
    std::cout << std::endl;
    std::cout << "|\033[33m     Index\033[0m|" << "\033[34mFirst name\033[0m|" << " \033[36mLast name\033[0m|" << "  \033[32mNickname\033[0m|" << std::endl;
    std::cout << "|-.- -.- -.- -.- -.- -.- -.- -.- -.- -.- -.-|" << std::endl;
    while (contactIndex < 8)
    {
        if (phone.contacts[contactIndex].isEmptyFirstName(phone.contacts[contactIndex]))
            break ;
        std::cout << "|" << std::setw(10) << contactIndex << "|";
        contacts[contactIndex].printFormattedContactInfo(contacts[contactIndex], 1);
        std::cout << "|";
        contacts[contactIndex].printFormattedContactInfo(contacts[contactIndex], 2);
        std::cout << "|";
        contacts[contactIndex].printFormattedContactInfo(contacts[contactIndex], 3);
        std::cout << "|\n";
        std::cout << std::endl;
        contactIndex++;
    }
    std::cout << MAGENTA << "| <3  <3  <3  <3  <3  <3  <3  <3  <3  <3  <3|" << RESET << std::endl;
    lastValidIndex = contactIndex - 1;
    while (true)
    {
        std::cout << std::endl;
        std::cout << YELLOW << "Please select the index for more info: " << RESET << std::endl;
        std::cout << std::endl;
        getline(std::cin, chosenIndex);
          if (std::cin.eof())
        {
            std::cout << RED << "EXIT PROGRAM" << RESET << std::endl;
            exit(0);
        }
        chosenIndex.erase(0, chosenIndex.find_first_not_of(" \t\v\f\r"));
        while (std::isspace(chosenIndex[chosenIndex.length() - 1]))
            chosenIndex.erase(chosenIndex.find_last_not_of(" \t\v\r\f") + 1, chosenIndex[chosenIndex.length() - 1]);
        if (chosenIndex.empty())
            continue ;
        if (isSingleDigitInRange(chosenIndex, lastValidIndex))
            contactIndex = (int)chosenIndex[0] - 48;
        else
        {
            std::cout << std::endl;
            std::cout << RED << "Please enter a valid number." << RESET << std::endl;
            std::cout << std::endl;
            continue;
        }
        phone.contacts[contactIndex].displayColorfulContactInfo(phone.contacts[contactIndex]);
        break ;
    }
}