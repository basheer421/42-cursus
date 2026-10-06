/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:45:18 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 22:31:37 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon		*weapon;
public:
	std::string getName(void);
	void		setName(std::string name);
	Weapon		&getWeapon(void);
	void		setWeapon(Weapon& weapon);
	void		attack();
	HumanB(std::string name);
	~HumanB();
};

#endif // HUMANB_HPP