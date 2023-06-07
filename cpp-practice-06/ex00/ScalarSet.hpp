/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSet.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:22:32 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 20:36:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ScalarSet
{
	public:
		int		Integer;
		float	Float;
		double	Double;

	ScalarSet();
	ScalarSet(int Integer, float Float, double Double);
	ScalarSet(const ScalarSet& src);
	ScalarSet & operator = (const ScalarSet& src);
	~ScalarSet();

	char getCharacter() const;
};
