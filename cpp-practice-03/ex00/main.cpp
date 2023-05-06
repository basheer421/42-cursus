/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:52:29 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:54:14 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{	
	ClapTrap n1("calp1");
	ClapTrap n2;
	
	n1.attack(n2.getName());
	n1.attack(n2.getName());
	n2.takeDamage(n1.getAttackDamage());
	n2.attack(n1.getName());
	n1.takeDamage(n2.getAttackDamage());
	n1.beRepaired(9);
	n2.beRepaired(1);
	
	return (0);
}
