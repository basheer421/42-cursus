/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:08:07 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 14:32:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& src);
	~Dog();
	Dog & operator = (const Dog& src);

	void makeSound() const;
	Brain* getBrain() const;

};

#endif // DOG_HPP