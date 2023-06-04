/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSet.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:22:32 by bammar            #+#    #+#             */
/*   Updated: 2023/06/04 23:54:05 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ScalarSet
{
	public:
		char Character;
		int Integer;
		float Float;
		double Double;

	ScalarSet();
	ScalarSet(char Character, int Integer, float Float, double Double);
	ScalarSet(const ScalarSet& src);
	ScalarSet & operator = (const ScalarSet& src);
	~ScalarSet();
};
