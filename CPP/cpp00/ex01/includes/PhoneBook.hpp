#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[9];
    public:
        PhoneBook();
        ~PhoneBook();
        int         check_pb(PhoneBook pb);
        PhoneBook   del_one(PhoneBook pb);
        void        display(PhoneBook pb);
        PhoneBook        add_i(PhoneBook pb, int i);
};

#endif