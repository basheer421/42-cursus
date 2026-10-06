/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:02:28 by bammar            #+#    #+#             */
/*   Updated: 2023/04/05 22:35:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * Signed area method
 * if we connect the dot with all verts
 * and make triangles out of that,
 * these triangles areas sum should be
 * 	equal to the triangle area if the point is inside.
 * "A = 0.5 * (x1y2 + x2y3 + x3y1 - x1y3 - x2y1 - x3y2))"
 * Which is equal to : (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2)
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed x=point.getX(), y=point.getY();
    Fixed x1=a.getX(), y1=a.getY();
    Fixed x2=b.getX(), y2=b.getY();
    Fixed x3=c.getX(), y3=c.getY();

    Fixed bigArea = ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)).toFloat() / (2.0f);
    Fixed area1 = ((x2 - x) * (y3 - y) - (x3 - x) * (y2 - y)).toFloat() / (2.0f);
    Fixed area2 = ((x3 - x) * (y1 - y) - (x1 - x) * (y3 - y)).toFloat() / (2.0f);
    Fixed area3 = ((x1 - x) * (y2 - y) - (x2 - x) * (y1 - y)).toFloat() / (2.0f);
	if (area1.toFloat() < 0.001f || area2.toFloat() < 0.001f || area3.toFloat() < 0.001f)
		return (false);
    return ((area1 + area2 + area3 - bigArea).toFloat() < 0.001f);
}
