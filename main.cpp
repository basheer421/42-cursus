/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/19 06:09:52 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ft/vector.hpp"
#include <vector>
#include <stack>
#include "ft/stack.hpp"
#include "ft/utils/pair.hpp"


void print_container(ft::vector<ft::pair<int, double> > c) 
{
    for (ft::vector<ft::pair<int, double> >::iterator it = c.begin(); it != c.end(); it++)
    {
      std::cout << (*it).first << ", " << (*it).second;
      std::cout << '\n';
    }
}


int main ()
{
  // int x[] = {1, 2, 3, 4};
  // ft::vector<int> myvector (x,x+4);        // vector with 2 elements
  // ft::vector<int> vec2(myvector.begin(), myvector.end());
  ft::vector<ft::pair<int, double> > p;

  p.push_back(ft::make_pair(5, 3.3));
  p.push_back(ft::make_pair(6, 7.3));
  p.push_back(ft::make_pair(6, -7.3));
  print_container(p);

  // for (int i = 0; i < (int)myvector.size(); i++)
  //   std::cout << myvector[i] << "\n";

  return 0;
}