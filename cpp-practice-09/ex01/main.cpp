/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:49:26 by bammar            #+#    #+#             */
/*   Updated: 2023/06/25 19:49:49 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int _stoi(std::string s)
{
	std::stringstream ss(s);
	int i;

	ss >> i;
	return i;
}

int exitWithError()
{
	std::cerr << "Error\n";
	return (1);
}

int main(int argc, char **argv)
{
	std::stack<int> stack;

	if ((argc != 2) || std::string(argv[1]).length() == 0)
	{
		std::cerr << "Error\n";
		return (1);
	}
	std::stringstream ss((std::string(argv[1])));
	std::string buff;

	while (std::getline(ss, buff, ' '))
	{
		if (buff.length() == 0)
			continue ;
		if ((buff.length() != 1) || (!std::isdigit(buff[0])
			&& (buff[0] != '*') && (buff[0] != '/') && (buff[0] != '+') && (buff[0] != '-')))
			return exitWithError();
		if (std::isdigit(buff[0]))
		{
			stack.push(_stoi(buff));
		}
		else
		{
			int nums[2];
			if (stack.empty())
				return exitWithError();
			nums[0] = stack.top();
			stack.pop();
			if (stack.empty())
				return exitWithError();
			nums[1] = stack.top();
			stack.pop();
			switch (buff[0])
			{
				case '+':
					stack.push(nums[1] + nums[0]); break;
				case '-':
					stack.push(nums[1] - nums[0]); break;
				case '*':
					stack.push(nums[1] * nums[0]); break;
				case '/':
					stack.push(nums[1] / nums[0]); break;
				default:
					break ;
			}
		}
	}
	if (stack.empty())
		return exitWithError();
	int out = stack.top();
	stack.pop();
	
	if (!stack.empty())
		return exitWithError();
	
	std::cout << out << "\n";
	return (0);
}
