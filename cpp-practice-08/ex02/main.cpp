/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:07:27 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 15:47:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>

int main()
{
    MutantStack<int> mstack;
    std::list<int> intList;
    mstack.push(5); intList.push_back(5); // 5

    mstack.push(17); intList.push_back(17); // 5 17

    std::cout << mstack.top() << std::endl;

    mstack.pop(); intList.pop_back();  // 5
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);  intList.push_back(3); // 5 3
    mstack.push(5); intList.push_back(5);  // 5 3 5
    mstack.push(737); intList.push_back(737); // 5 3 5 737
    //[...]
    mstack.push(0);  intList.push_back(0); // 5 3 5 737 0
    
    std::cout << "-----\n";
    {
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "-----\n";

    {
        std::list<int>::iterator it = intList.begin();
        std::list<int>::iterator ite = intList.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::stack<int> s(mstack);
    return 0;
}