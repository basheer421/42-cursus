/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:38:47 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:15:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string	 plainName;
public:
	DiamondTrap(std::string name);
	DiamondTrap();
	~DiamondTrap();

	void attack(const std::string& target);
	void setPlainName(std::string n);
	void whoAmI();

};

#endif // DIAMONDTRAP_HPP
