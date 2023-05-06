/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:38:47 by bammar            #+#    #+#             */
/*   Updated: 2023/04/06 07:05:14 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap();
	~FragTrap();

	void attack(const std::string& target);
	void highFivesGuys(void);

};

#endif // FRAGTRAP_HPP
