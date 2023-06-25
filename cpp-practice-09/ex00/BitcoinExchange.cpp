/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:42:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 18:38:48 by bammar           ###   ########.fr       */
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
			list.push_back(buff);
	return list;
}

static bool isInt(const std::string& s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

static bool isFloat(const std::string& s)
{
	bool pointReached = false;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
		{
			if (!pointReached && s[i] == '.' && i+1 != s.length())
				pointReached = true;
			else if (!pointReached && s[i] == '.' && i+1 == s.length())
				return false;
			else if (pointReached || s[i] != '.')
				return (false);
		}
	}
	return (true);
}

BitcoinExchange::BitcoinExchange()
{
	storeDB("data.csv", this->db, ',');	
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
		if ((dateString.length() == 0) || (valueString.length() == 0) || !isFloat(valueString))
			throw BadFile();
		std::list<std::string> dateList = split(dateString, '-');
		db[dateString] = _stod(valueString);
	}
}

void BitcoinExchange::calculate(std::string fileName,
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
			std::cout <<  "Error: bad input => " + buff << "\n";
			continue ;
		}
		std::string dateString = buff.substr(0, sep - 1);
		std::string valueString = buff.substr(sep+2);
		std::list<std::string> dateList = split(dateString, '-');
		double val = ( _stod(valueString) );
		if (isBadDate(dateList))
			std::cout << "Error: bad input => " << dateString << "\n";
		else if ((val < 0) || !isInt(valueString))
			std::cout <<  "Error: not a positive number.\n";
		else if (val > 1000)
			std::cout << "Error: too large a number.\n";
		else
		{
			std::cout << dateString << " => " << valueString << " = " <<
				val * findNearsetDate(dateString) << "\n";
		}
	}
}

bool BitcoinExchange::isBadDate(std::list<std::string> dateList)
{
	int type = 0; // year(0) - month(1) - day(2)
	for (std::list<std::string>::iterator it = dateList.begin(); it != dateList.end(); it++)
	{

		if (!isInt(*it))
			return true;
		std::stringstream ss(*it);
		int i;

		ss >> i;
		if ((i <= 0) || (i > std::numeric_limits<int>::max()))
			return true;
		if (((type == 1) && (i > 12)) || ((type == 2) && (i > 31)))
			return true;
		++type;
	}
	return false;
}

double BitcoinExchange::findNearsetDate(std::string date)
{
	if (db.count(date) == 1)
		return (db.at(date));
	db[date] = 0;
	std::map<std::string, double>::iterator it =  db.find(date);
	--it;
	double val = ((*it).second);
	db.erase(++it);
	return val;
}

const char *BitcoinExchange::BadFile::what() const throw()
{
	return ("could not open file.");
}
