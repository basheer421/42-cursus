/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:22:34 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:14:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <sstream>

class ClapTrap
{
private:
	std::string	 name;
	unsigned int healthPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();
	ClapTrap & operator = (const ClapTrap& src);
	ClapTrap(const ClapTrap& src);


	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	 getName(void) const;
	unsigned int getHealthPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackDamage(void) const;

	void setName(std::string n);
	void setHealthPoints(unsigned int p);
	void setEnergyPoints(unsigned int p);
	void setAttackDamage(unsigned int p);
};

#endif // CLAPTRAP_HPP
