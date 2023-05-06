/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:02:41 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 15:37:37 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    ICharacter *me = new Character("me");
    ICharacter *mark = new Character("mark");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	mark->equip(new Ice());
	mark->equip(new Cure());
	mark->equip(new Cure());
	mark->equip(new Cure());
	Ice *ice = new Ice();
	mark->equip(ice);
	delete ice;
	mark->use(3, *mark);
	mark->unequip(3);
	mark->unequip(2);
	mark->unequip(3);
	mark->unequip(1);
	mark->unequip(3);
	mark->unequip(3);
	mark->unequip(3);
	mark->unequip(0);
	mark->use(3, *mark);
	mark->equip(new Ice());
	mark->use(3, *mark);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete mark;
    delete src;
	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// 	return 0;
	// }
    return 0;
}
