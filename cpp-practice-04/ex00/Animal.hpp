/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:49:25 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 11:29:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include <sstream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& src);
	Animal & operator = (const Animal& src);
	virtual ~Animal();
	
	virtual void makeSound() const;

	std::string getType() const;
	void setType(std::string type);
};


#endif // ANIMAL_HPP