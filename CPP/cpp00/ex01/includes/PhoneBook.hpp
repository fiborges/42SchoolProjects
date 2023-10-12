/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:49:05 by firibeir          #+#    #+#             */
/*   Updated: 2023/10/02 15:08:08 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        // Displays the contacts in a user-friendly format.
        void        showContacts(PhoneBook phone);
        // Adds a new contact at a specific index in the phone book.
        void        addContactAtIndex();
};

#endif