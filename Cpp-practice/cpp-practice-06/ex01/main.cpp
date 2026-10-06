/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:03:03 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 17:45:16 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Data &data)
{
	out << "[";
	out << data.type << ", " << data.color << ", " << data.size << "]";
	return (out);
}

int main(void)
{
	Data		*data;

	data = new Data("A", "Green", "XL");
	data = Serializer::deserialize(Serializer::serialize(data));
	std::cout << *data << "\n";	

	delete data;
	return (0);
}
