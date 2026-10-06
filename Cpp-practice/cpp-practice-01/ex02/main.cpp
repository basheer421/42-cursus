/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:49:04 by bammar            #+#    #+#             */
/*   Updated: 2023/02/17 16:45:17 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "Address 1: " << &str << "\n";
	std::cout << "Address 2: " << strPTR << "\n";	
	std::cout << "Address 3: " << &strREF << "\n";

	std::cout << "str 1: " << str << "\n";
	std::cout << "str 2: " << *strPTR << "\n";	
	std::cout << "str 3: " << strREF << "\n";
	return (0);	
}
