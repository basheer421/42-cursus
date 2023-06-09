/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:33:13 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 17:24:09 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdint.h>

class Data
{
	public:
		std::string type;
		std::string	color;
		std::string size;

		Data();
		Data(std::string type, std::string color, std::string size);
		~Data();
		Data(const Data& src);
		Data& operator = (const Data& src);
};
