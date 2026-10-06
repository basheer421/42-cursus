/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSet.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:22:32 by bammar            #+#    #+#             */
/*   Updated: 2023/06/08 17:52:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarSet
{
	public:
		int		Integer;
		float	Float;
		double	Double;
		bool NaN;
		std::string sf;
		std::string sd;

	ScalarSet();
	ScalarSet(int Integer, float Float, double Double);
	ScalarSet(const ScalarSet& src);
	ScalarSet(std::string s);
	ScalarSet & operator = (const ScalarSet& src);
	~ScalarSet();

	char getCharacter() const;
	
};
