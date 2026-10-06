/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:49 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 10:32:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_HPP
# define AMateria_HPP

#include <string>
#include <iostream>
#include "Character.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& src);
	AMateria & operator = (const AMateria& src);
	AMateria(std::string const & type);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif // AMateria_HPP