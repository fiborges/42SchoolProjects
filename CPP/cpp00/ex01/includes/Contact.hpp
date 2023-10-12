/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:58 by firibeir          #+#    #+#             */
/*   Updated: 2023/10/02 15:18:37 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN     "\033[36m"
#define MAGENTA  "\033[35m"

//stores the contact information
class Contact
{
// only accessible from within the class itself
//This is used to encapsulate and hide implementation details, 
//and to prevent the code from being accidentally misused.
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;
// accessible from outside the class    
public:
    //A constructor is a special member function that gets called when an object of the class is created. It is responsible for initializing the object's state.
    Contact();
    // A destructor is another special member function, identified by the ~ symbol followed by the class name. It is called when an object goes out of scope or is explicitly deleted. 
    ~Contact();
    
    // Parameterized constructor to initialize contact information.
    Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
    
    // Checks if the first name of a contact is empty and returns 1 if it is, 0 otherwise.
    int         isEmptyFirstName(Contact contact);
    // Displays contact information with colorful formatting.
    void        displayColorfulContactInfo(Contact contact);
    // Prints specific contact information with proper formatting based on the provided index.
    void        printFormattedContactInfo(Contact contact, int i);
};

#endif