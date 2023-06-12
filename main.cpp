/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/12 22:33:13 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ft/vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<std::string> f(5);
	std::vector<std::string> s(5);
	
	ft::vector<int> f2;
	std::vector<int> s2;


	f2.assign(2, 11);
	s2.assign(2, 11);
	f2.push_back(88);
	s2.push_back(88);

	std::cout << f2[0] << "\n";
	std::cout << s2[0] << "\n";

	std::string x("lol");
	
	for (size_t i = 0; i < f.size(); i++)
		f[i] = "hi";
	for (size_t i = 0; i < s.size(); i++)
		s[i] = "hi";
	
	f.resize(7, "k");
	s.resize(7, "k");

	f.push_back("ok");
	s.push_back("ok");

	f.push_back(x);
	s.push_back(x);

	f.pop_back();
	std::cout << x << "\n";
	s.pop_back();
	std::cout << x << "\n";

	f.assign(2, "man");
	s.assign(2, "man");

	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i] << "\n";

	std::cout << "----\n";

	for (size_t i = 0; i < s.size(); i++)
		std::cout << s[i] << "\n";


	std::cout << f.capacity() << "\n";
	std::cout << s.capacity() << "\n";

	std::cout << "----\n";
	ft::vector<std::string> f3(f);

	std::cout << f3.capacity() << "\n";

	for (size_t i = 0; i < f.size(); i++)
		std::cout << f3[i] << "\n";

	std::cout << "----\n";



	return (0);
}
