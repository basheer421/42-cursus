/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:33:52 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 15:13:48 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		slots[i] = NULL;
		used[i] = false;
	}
}

Character::Character()
{
	Character("noname");
}

Character::Character(const Character& src)
{
	*this = src;
}

Character & Character::operator = (const Character& src)
{
	if (this == &src)
		return (*this);
	this->name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		delete slots[i];
		slots[i] = src.slots[i];
		used[i] = src.used[i];
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!used[i])
		{
			delete slots[i];
			slots[i] = m;
			used[i] = true;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	used[idx] = false;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (slots[idx])
		slots[idx]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (slots[i])
			delete slots[i];
}
