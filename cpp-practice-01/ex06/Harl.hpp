/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:09:21 by bammar            #+#    #+#             */
/*   Updated: 2023/02/21 01:01:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

#define CMD_COUNT 4
class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif