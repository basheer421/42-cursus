/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:48:10 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:55:45 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name):ClapTrap(name) {
	setAttackDamage(30);
	setEnergyPoints(100);
	setHealthPoints(100);
	std::cout << "Frag Constructor of " << getName() << "\n";
}

FragTrap::FragTrap() {FragTrap("null");}

FragTrap::~FragTrap() {
	std::cout << "Frag destructor of " << getName() << "\n";
}

void FragTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0 || getHealthPoints() == 0)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout <<
		"FragTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " requests high fives\n";
}
