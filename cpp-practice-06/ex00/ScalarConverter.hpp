/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:34 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 16:38:07 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "ScalarSet.hpp"

class ScalarConverter
{
	
	private:
		typedef enum {
			INT,
			CHAR,
			DOUBLE,
			FLOAT,
			NONE
		} t_type;

		ScalarConverter();
		ScalarConverter& operator = (const ScalarConverter& src);
		static t_type getType(std::string& s);

	protected:
		class InvalidTypeException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	public:
		static ScalarSet convert(const std::string s);
};
