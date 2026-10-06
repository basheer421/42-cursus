/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 02:22:31 by bammar            #+#    #+#             */
/*   Updated: 2023/04/01 07:59:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>

# define MAX_CONTACT 8

class PhoneBook
{
private:
	Contact contacts[MAX_CONTACT];
	int		counter;
	int		current_size;
public:
	PhoneBook();
	~PhoneBook();
	void addContact(Contact contact);
	int getCurrentSize();
	void displayAllContacts();
	void displayContact(int index);
};

#endif // PHONEBOOK_HPP