/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:42:00 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 01:14:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <list>

std::list<std::string> split(std::string str, char sep);

class BitcoinExchange
{
	private:
		struct Date
		{
			std::string raw;
			std::string year;
			int month;
			int day;
		};

		std::map<std::string, float> db;
		void storeInput(std::string fileName); // Stores inside the db.
	
	public:
		BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		
};
