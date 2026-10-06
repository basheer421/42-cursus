/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 02:31:36 by bammar            #+#    #+#             */
/*   Updated: 2023/04/01 08:00:46 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


static void display_10_chars(std::string s)
{
	if (s.length() > 10)
			std::cout << s.substr(0, 9) << ".";
	else
	{
		for (int x = 0; x < (10 - (int)s.length()); x++)
			std::cout << " ";
		std::cout << s;
	}
}

PhoneBook::PhoneBook()
{
	PhoneBook::counter = 0;
	PhoneBook::current_size = 0;
}

PhoneBook::~PhoneBook(){}

int PhoneBook::getCurrentSize()
{
	return (current_size);
}

void PhoneBook::addContact(Contact contact)
{
	if (counter == MAX_CONTACT)
		counter = 0;
	if (current_size < MAX_CONTACT)
		current_size++;
	contacts[counter++] = contact;
}

void	PhoneBook::displayAllContacts()
{
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << "----------|----------|----------|----------\n";
	for (int i = 0; i < current_size; i++)
	{
		std::stringstream ss;
		ss << i;
		display_10_chars(ss.str());
		std::cout << "|";
		display_10_chars(contacts[i].getFirstName());
		std::cout << "|";
		display_10_chars(contacts[i].getLastName());
		std::cout << "|";
		display_10_chars(contacts[i].getNickName());
		std::cout << "\n";
	}
}

void	PhoneBook::displayContact(int i)
{
	std::cout << "First name: " << contacts[i].getFirstName() << "\n";
	std::cout << "Last name: " << contacts[i].getLastName() << "\n";
	std::cout << "Nickname: " << contacts[i].getNickName() << "\n";
	std::cout << "Phone number: " << contacts[i].getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << "\n";
}
