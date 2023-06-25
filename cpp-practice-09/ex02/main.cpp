/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:00:50 by bammar            #+#    #+#             */
/*   Updated: 2023/06/26 01:47:39 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isInt(const std::string& s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

static int _stol(std::string s)
{
	std::stringstream ss(s);
	long i;

	ss >> i;
	if (ss.bad() || (i < 0) || (i > std::numeric_limits<int>::max())
		|| !isInt(s))
		return (-1);
	return static_cast<int>(i);
}

static int exitWithError()
{
	std::cerr << "Error\n";
	return (1);
}

int main(int argc, char **argv)
{
	
	std::vector<int> vec;
	std::deque<int> dq;
	
	for (int i = 1; i < argc; i++)
	{
		int n = _stol(argv[i]);
		if (n == -1)
			return exitWithError();
		vec.push_back(n);
		dq.push_back(n);
		
	}

	std::cout << "Before: ";
	for (size_t i = 0 ; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	
	std::cout << "\n";

	std::clock_t vs = std::clock();
	merge_insertion_sort(vec);
	std::clock_t ve = std::clock();

	std::clock_t dqs = std::clock();
	merge_insertion_sort(dq);
	std::clock_t dqe = std::clock();

	std::cout << "After: ";
	for (size_t i = 0 ; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	
	std::cout << "\n";
	std::cout << "Time to process a range of " << (argc - 1)
		<< " elements with std::vector : "
		<< std::fixed << std::setprecision(5)
		<< (static_cast<double>(ve - vs) / CLOCKS_PER_SEC) * 1000000.0
		<< " us\n";
	std::cout << "Time to process a range of " << (argc - 1)
		<< " elements with std::deque : "
		<< std::fixed << std::setprecision(5)
		<< (static_cast<double>(dqe - dqs) / CLOCKS_PER_SEC) * 1000000.0
		<< " us\n";
	return (0);
}
