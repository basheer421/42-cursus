/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:36:42 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 22:28:47 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon		*weapon;
public:
	std::string getName(void);
	void		setName(std::string name);
	Weapon&		getWeapon(void);
	void		setWeapon(Weapon& weapon);
	void		attack();
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
};

#endif // HUMANA_HPP