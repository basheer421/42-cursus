/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:45:12 by bammar            #+#    #+#             */
/*   Updated: 2023/06/26 01:52:47 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <limits>
#include <ctime>
#include <iomanip>

# define K_size 4

template <typename cont>
void insertion_sort(cont& seq, std::size_t s, std::size_t end)
{
	int n = end;
    for (int i = s; i < n; i++) {
        int key = seq[i];
        int j = i - 1;
        while (j >= 0 && seq[j] > key) {
            seq[j + 1] = seq[j];
            j--;
        }
        seq[j + 1] = key;
	}
}

template <typename cont>
void merge(cont& seq, std::size_t s, std::size_t e1, std::size_t e2)
{
    std::size_t i = s, j = e1 + 1;
    cont temp;

    while ((i <= e1) && (j <= e2))
    {
        if (seq[i] > seq[j])
            temp.push_back(seq[j++]);
        else
            temp.push_back(seq[i++]);
    }
    while (i <= e1)
        temp.push_back(seq[i++]);
	while (j <= e2)
		temp.push_back(seq[j++]);
	
	for (std::size_t x = temp.size() - 1; x >= 0; x--)
	{
		temp[x + s] = temp[x];
	}
}


template <typename cont>
void sort(cont& seq, std::size_t s, std::size_t e)
{
	if (e - s > K_size)
	{
		std::size_t mid = (e + s) / 2;
		sort(seq, s, mid);
		sort(seq, mid + 1, e);
		merge(seq, s, mid, e);
	}
	else
		insertion_sort(seq, s, e);

}

template <typename cont>
void merge_insertion_sort(cont& seq)
{
	sort(seq, 0, seq.size()-1);
}
