/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:52:58 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 18:35:26 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}

	try
	{
		BitcoinExchange bt;
		bt.calculate(argv[1], '|');
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return (1);
	}

	return (0);
}
