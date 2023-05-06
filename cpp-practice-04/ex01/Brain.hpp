/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:54:59 by bammar            #+#    #+#             */
/*   Updated: 2023/04/07 12:04:27 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain& src);
	Brain & operator = (const Brain& src);
	~Brain();
	
	std::string ideas[100];
	
};

#endif // BRAIN_HPP