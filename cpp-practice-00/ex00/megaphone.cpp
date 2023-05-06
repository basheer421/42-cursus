/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:19:10 by bammar            #+#    #+#             */
/*   Updated: 2023/03/29 23:27:42 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string s;

	for (int i = 1; i < argc; i++)
	{
		s = argv[i];
		for (size_t j = 0; j < s.length(); j++)
			s[j] = std::toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
