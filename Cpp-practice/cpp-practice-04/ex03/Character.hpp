/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:57:31 by bammar            #+#    #+#             */
/*   Updated: 2023/04/08 14:48:15 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
#define Character_HPP

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
private:
  std::string name;
  AMateria *slots[4];
  bool used[4];

public:
  Character();
  Character(std::string name);
  ~Character();
  Character(const Character &src);
  Character &operator=(const Character &src);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif // Character_HPP