#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        int i;
        Contact contacts[9];
    public:
        PhoneBook();
        ~PhoneBook();
        // Counts the number of non-empty contacts in the phone book.
        int         countNonEmptyContacts(PhoneBook phone);
        // Shifts the contacts in the phone book to remove empty slots.
        PhoneBook   shiftContactsBack(PhoneBook phone);
        // Displays the contacts in a user-friendly format.
        void        showContacts(PhoneBook phone);
        // Adds a new contact at a specific index in the phone book.
        void        addContactAtIndex();
};

#endif