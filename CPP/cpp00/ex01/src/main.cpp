/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:49:21 by firibeir          #+#    #+#             */
/*   Updated: 2023/10/02 15:07:45 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string command;
    PhoneBook phone;
    int     i;

    i = 0;
    while (true)
    {
        std::cout << std::endl;
        std::cout << CYAN << "Enter a command: (ADD, SEARCH, EXIT)" << RESET << std::endl;
        std::cout << std::endl;
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << RED << "EXIT PROGRAM" << RESET << std::endl;
            exit(0);
        }
        std::cout << std::endl;
        command.erase(0, command.find_first_not_of(" \t\v\f\r"));
        while (isspace(command[command.length() - 1]))
            command.erase(command.find_last_not_of(" \t\v\r\f") + 1, command[command.length() - 1]);
        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {
            i = phone.countNonEmptyContacts(phone);
            if (i > 7)
            {
                i = -42;
                while (i == -42)
                {
                    std::cout << RED << "Attention! Maximum number of contacts reached, If you continue the oldest contact will be deleated in order to add the new one. (Y/N):" << RESET << std::endl;
                    std::getline(std::cin, command);
                    if (std::cin.eof())
                    {
                        std::cout << RED << "EXIT PROGRAM" << RESET << std::endl;
                        exit(0);
                    }
                    command.erase(0, command.find_first_not_of(" \t\v\f\r"));
                    while (isspace(command[command.length() - 1]))
                        command.erase(command.find_last_not_of(" \t\v\r\f") + 1, command[command.length() - 1]);
                    if (command == "Y" || command == "y")
                    {
                        phone.addContactAtIndex();
                        i = 0;
                    }
                    else if (command == "N" || command == "n")
                        i = -1;
                    else
                        std::cout << RED << "Not valid entrance!, try again." << RESET << std::endl;
                }
            }
            else
                phone.addContactAtIndex();
        }
        else if (command == "SEARCH")
            phone.showContacts(phone);
        else if (command.empty())
            continue ;
        else
            std::cout << RED << "Not a valid command! Try again" << RESET << std::endl;
    }
}