/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:34:29 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:55:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	setName(name);
	setAttackDamage(0);
	setEnergyPoints(10);
	setHealthPoints(10);
	std::cout << "Constructor of " << getName() << "\n";
}

ClapTrap::ClapTrap() {ClapTrap("null");}

ClapTrap& ClapTrap::operator = (const ClapTrap& src) {
	setName(src.getName());
	setAttackDamage(src.getAttackDamage());
	setEnergyPoints(src.getEnergyPoints());
	setHealthPoints(src.getHealthPoints());
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	*this = src;
}

void ClapTrap::attack(const std::string& target) {
	
	if (getEnergyPoints() == 0 || getHealthPoints() == 0)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout <<
		"ClapTrap " << getName() << " attacks " << target << ", causing "
		<< getAttackDamage() << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (getEnergyPoints() == 0 || getHealthPoints() == 0)
		return ;

	if (getHealthPoints() <= amount)
		setHealthPoints(0);	
	else
		setHealthPoints(getHealthPoints() - amount);
	std::cout << "ClapTrap " << getName() << " took " << amount << " damage.\n";
	if (getHealthPoints() == 0)
		std::cout << "ClapTrap " << getName() << " has died\n";
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (getEnergyPoints() == 0 || getHealthPoints() == 0)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	setHealthPoints(getHealthPoints() + amount);
	std::cout << "ClapTrap " << getName()
		<< " is repaired by " << amount << " points\n";
}

std::string ClapTrap::getName(void) const {
    return (name);
}

unsigned int ClapTrap::getHealthPoints(void) const {
    return (healthPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return (energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return (attackDamage);
}

void ClapTrap::setName(std::string n) {
	this->name = n;
}

void ClapTrap::setHealthPoints(unsigned int p) {
	this->healthPoints = p;
}

void ClapTrap::setEnergyPoints(unsigned int p) {
	this->energyPoints = p;
}

void ClapTrap::setAttackDamage(unsigned int dmg) {
	this->attackDamage = dmg;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor of " << name << "\n";
}
