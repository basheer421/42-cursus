/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:42:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 01:22:00 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

double _stod(std::string s)
{
	std::stringstream ss(s);
	double i;

	ss >> i;
	return i;
}

std::list<std::string> split(std::string str, char sep)
{
	std::list<std::string> list;
	std::stringstream ss(str);
	std::string buff;

	while (std::getline(ss, buff, sep))
	{
		// not needed for easy error detection
		// if (buff.length() > 0)
			list.push_back(buff);
	}
	return list;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
	storeInput(fileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this == &src)
		return *this;
	this->db = src.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::storeInput(std::string fileName)
{
	// bool isDate = true;
	std::fstream file(std::string(fileName).c_str(), std::fstream::in);
	std::stringstream stream;
	std::string buff;

	stream << file.rdbuf();
	while (std::getline(stream, buff, '\n'))
	{
		if (buff.length() == 0)
			continue;
		std::size_t comma = buff.find(',');
		if (comma == std::string::npos)
			return ;
		std::string dateString = buff.substr(0, comma);
		std::string valueString = buff.substr(comma + 1);
		std::list<std::string> dateList = split(dateString, '-');
		
		// Date date;
		// date.raw = dateString;
		// date.year = dateList.front();
		// dateList.pop_front();
		// date.month = static_cast<long>(_stod(dateList.front()));
		// dateList.pop_front();
		// date.day = static_cast<long>(_stod(dateList.front()));
		// dateList.pop_front(); 
		
		db[dateString] = _stod(valueString);
	}
}
