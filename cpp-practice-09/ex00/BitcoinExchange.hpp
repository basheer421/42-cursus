/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:42:00 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 17:21:39 by bammar           ###   ########.fr       */
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
#include <limits>

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

		void storeDB(std::string fileName,
			std::map<std::string, double>& db,
			char dateSep);
		
		bool isBadDate(std::list<std::string> dateList);
		double findNearsetDate(std::string date);
		

		class BadFile : public std::exception {
			public:
				const char *what() const throw();
		};
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void printDB();
		void calculate(std::string fileName, char dateSep);

		
};
