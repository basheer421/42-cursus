/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:45:12 by bammar            #+#    #+#             */
/*   Updated: 2023/06/26 15:28:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <iomanip>

# define K_size 5

template <typename cont>
void insertion_sort(cont& seq, std::size_t s, std::size_t end)
{
	for (std::size_t i = s + 1; i < end; i++)
        for (std::size_t y = i; y > 0 && seq[y] < seq[y-1]; y--)
            std::swap(seq[y-1], seq[y]);
}

template <typename cont>
void merge(cont& seq, std::size_t const s, std::size_t const m, std::size_t const e)
{
    std::size_t n1 = m - s + 1;
    std::size_t n2 = e - m;

    cont L(n1);
    cont R(n2);

    for (std::size_t i = 0; i < n1; i++)
        L[i] = seq[s + i];
    for (std::size_t i = 0; i < n2; i++)
        R[i] = seq[m + i + 1];

    std::size_t i = 0, j = 0;
    std::size_t k = s;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            seq[k] = L[i++];
        else
            seq[k] = R[j++];
        k++;
    }

    // Remaining
    while (i < n1)
        seq[k++] = L[i++];
    while (j < n2)
        seq[k++] = R[j++];
}


template <typename cont>
void sort(cont& seq, std::size_t s, std::size_t e)
{
    if (s < e)
    {
        if (e - s + 1 <= K_size)
            insertion_sort(seq, 0, seq.size());
        else
        {
            std::size_t mid = s + (e - s) / 2;
            sort(seq, s, mid);
            sort(seq, mid + 1, e);
            merge(seq, s, mid, e);
        }
    }

}

template <typename cont>
void merge_insertion_sort(cont& seq)
{
	sort(seq, 0, seq.size()-1);
}
