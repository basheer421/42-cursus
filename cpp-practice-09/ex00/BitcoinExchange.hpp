/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:42:00 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 02:19:33 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <exception>

std::list<std::string> split(std::string str, char sep);

class BitcoinExchange
{
	private:
		struct Date
		{
			std::string year;
			int month;
			int day;
		};

		std::map<std::string, double> db;
		std::map<std::string, std::string> input;
		std::map<std::string, bool> isBadInput; // could use set instead

		void storeDB(std::string fileName,
			std::map<std::string, double>& db,
			char dateSep);
		
		void storeInput(std::string fileName,
			std::map<std::string, std::string>& db,
			char dateSep);

		class BadFile : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	public:
		BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		
};
