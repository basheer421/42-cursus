/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:23:40 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 13:54:13 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *slots[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource & src);
	MateriaSource &operator=(const MateriaSource &src);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	
};

#endif