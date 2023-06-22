/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:43 by bammar            #+#    #+#             */
/*   Updated: 2023/06/22 21:51:40 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * Functions throw by type of error:
 *  - fail exception
 * 
*/

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>

class FailException : public std::exception {};

void default_constructor();

