/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/12 16:51:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ft/vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<std::string> f(3);
	std::vector<std::string> s(3);
	
	for (int i = 0; i < 3; i++)
		f[i] = "hi";
	for (int i = 0; i < 3; i++)
		s[i] = "hi";
	
	f.resize(2, "k");
	s.resize(2, "k");

	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i] << "\n";

	for (size_t i = 0; i < s.size(); i++)
		std::cout << s[i] << "\n";

	std::cout << f.capacity() << "\n";
	std::cout << s.capacity() << "\n";


	
	return (0);
}
