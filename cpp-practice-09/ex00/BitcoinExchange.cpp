/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:42:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 02:27:50 by bammar           ###   ########.fr       */
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
	try
	{
		storeDB("data.csv", this->db, ',');
		storeInput(fileName, this->input, '|');
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
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

void BitcoinExchange::storeDB(std::string fileName,
	std::map<std::string, double>& db,
	char dateSep)
{
	bool isFirst = true;
	std::fstream file(std::string(fileName).c_str(), std::fstream::in);
	std::stringstream stream;
	std::string buff;

	if (file.fail())
		throw BadFile();

	stream << file.rdbuf();
	while (std::getline(stream, buff, '\n'))
	{
		if ((buff.length() == 0) || isFirst)
		{
			isFirst = false;
			continue;
		}
		std::size_t sep = buff.find(dateSep);
		std::string dateString = buff.substr(0, sep);
		std::string valueString = buff.substr(sep + 1);
		std::list<std::string> dateList = split(dateString, '-'); 
		db[dateString] = _stod(valueString);
	}
}

void BitcoinExchange::storeInput(std::string fileName,
	std::map<std::string, std::string>& db,
	char dateSep)
{
	bool isFirst = true;
	std::fstream file(std::string(fileName).c_str(), std::fstream::in);
	std::stringstream stream;
	std::string buff;

	if (file.fail())
		throw BadFile();

	stream << file.rdbuf();
	while (std::getline(stream, buff, '\n'))
	{
		if ((buff.length() == 0) || isFirst)
		{
			isFirst = false;
			continue;
		}

		std::size_t sep = buff.find(dateSep);

		if (sep == std::string::npos)
		{
			db[buff] =  "bad input => " + buff;
			continue ;
		}
		std::string dateString = buff.substr(0, sep);
		std::string valueString = buff.substr(sep + 1);
		std::list<std::string> dateList = split(dateString, '-');
		double val = _stod(valueString);
		if (val < 0)
			db[buff] =  "not a positive number.";
		else if (val > 2147483647)
			db[buff] =  "too large a number.";
		else
			db[dateString] = (valueString);
	}
}

const char *BitcoinExchange::BadFile::what() const throw()
{
	throw ("could not open file.");
}