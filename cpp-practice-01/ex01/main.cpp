/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:48:39 by bammar            #+#    #+#             */
/*   Updated: 2023/02/02 01:46:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int		n;

	n = 3;
	horde = zombieHorde(n, "zoom");
	if (horde == nullptr)
		return (1);

	for (int i = 0; i < n; i++)
		horde[i].announce();

	delete[] (horde);
	return (0);
}
