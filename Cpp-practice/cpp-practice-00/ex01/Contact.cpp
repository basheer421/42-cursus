/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:51:21 by bammar            #+#    #+#             */
/*   Updated: 2023/04/01 08:00:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickName, std::string phoneNumber,
		std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}
Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::getFirstName()
{
	return this->firstName;
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}


std::string Contact::getLastName()
{
	return this->lastName;
}


void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}


std::string Contact::getNickName()
{
	return this->nickName;
}


void Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}


std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}


void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}


std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}


void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
