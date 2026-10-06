/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:19:41 by bammar            #+#    #+#             */
/*   Updated: 2023/02/21 01:21:01 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug(void)
{
	std::cout << "I love having extra bacon "
	"for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
	"I really do!\n";
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
	"You didn't put enough bacon in my burger! If you did, "
	"I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I've been coming for"
	"years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	int i;
	std::string cmds[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < CMD_COUNT; i++)
		if (level == cmds[i])
			break ;
	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "Probably complaining about insignificant problems\n";
	}
}
