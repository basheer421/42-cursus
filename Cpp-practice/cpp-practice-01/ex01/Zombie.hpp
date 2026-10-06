/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:53:30 by bammar            #+#    #+#             */
/*   Updated: 2023/02/02 01:33:13 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
	
public:
	Zombie(std::string name);
	
	Zombie();
	
	~Zombie();

	void setName(std::string name);

	void announce(void); 
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
