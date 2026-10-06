/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:48:39 by bammar            #+#    #+#             */
/*   Updated: 2023/04/01 08:30:10 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool add(PhoneBook &pb, t_contact_info info)
{
	if (info.firstName.length() == 0 || info.lastName.length() == 0
		|| info.nickName.length() == 0
		|| info.phoneNumber.length() == 0
		|| info.darkestSecret.length() == 0)
		return (false);
	
	pb.addContact(Contact(info.firstName, info.lastName,
		info.nickName, info.phoneNumber, info.darkestSecret));
	return (true);
}

static void	request_info(t_contact_info &info)
{
	std::cout << "First Name: ";
	std::cin >> info.firstName;
	std::cout << "\nLast Name: ";
	std::cin >> info.lastName;
	std::cout << "\nNick Name: ";
	std::cin >> info.nickName;
	std::cout << "\nPhone Number: ";
	std::cin >> info.phoneNumber;
	std::cout << "\nDarkest Secret: ";
	std::cin >> info.darkestSecret;
}

static bool	request_input(PhoneBook &phoneBook)
{
	std::string		input;
	t_contact_info	addInfo;
	int				index;

	if (!std::getline(std::cin, input))
		return (false);
	if (input == "EXIT")
		return (false);
	else if (input == "ADD")
	{
		request_info(addInfo);
		if (!add(phoneBook, addInfo))
			std::cout << "Please fill all fields.\n";
		std::cout << "Please Enter a command [ADD, SEARCH, EXIT]: ";
	}
	else if (input == "SEARCH")
	{
		phoneBook.displayAllContacts();
		std::cout << "Choose the index of the contact you want to display: ";
		if (!std::getline(std::cin, input))
			return (false);
		index = 0;
		std::stringstream ss(input);
		ss >> index;
		std::cout << "\n";
		if (index  >= phoneBook.getCurrentSize() || index < 0 || ss.fail())
			std::cout << "Choose within the given range please.\n";
		else
			phoneBook.displayContact(index);
		std::cout << "Please Enter a command [ADD, SEARCH, EXIT]: ";
	}
	return (true);
}


int main(void)
{
	PhoneBook		phoneBook;

	phoneBook = PhoneBook();
	std::cout << "Please Enter a command [ADD, SEARCH, EXIT]: ";
	while (request_input(phoneBook))
		(void)0;
	return (0);
}
