/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:49:25 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 11:45:41 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WANIMAL_HPP
# define WANIMAL_HPP

#include <string>
#include <iostream>
#include <sstream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal & operator = (const WrongAnimal& src);
	~WrongAnimal();
	
	void makeSound() const;

	std::string getType() const;
	void setType(std::string type);
};


#endif // ANIMAL_HPP