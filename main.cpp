/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:45:09 by bammar            #+#    #+#             */
/*   Updated: 2023/06/20 14:24:50 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ft/vector.hpp"
#include <vector>
#include <stack>
#include "ft/stack.hpp"
#include "ft/utils/pair.hpp"
#include "ft/utils/rb_tree.hpp"


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
  ft::rb_tree<std::string, std::string> tree;
  tree.insert(ft::make_pair("1", "wow"));
  tree.insert(ft::make_pair("-2", "ok"));
  tree.insert(ft::make_pair("3", "90"));
  tree.insert(ft::make_pair("4", "120"));
  tree.insert(ft::make_pair("550", "0"));
  tree.insert(ft::make_pair("4", "110"));

  std::cout << "Inorder traversal of the LLRB tree: ";
  tree.printInorder();
  std::cout << std::endl;

  return 0;
}