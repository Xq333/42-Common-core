/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:00:12 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 13:28:51 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {

  if ((a.getX() == point.getX() && a.getY() == point.getY()) ||
      (b.getX() == point.getX() && b.getY() == point.getY()) ||
      (c.getX() == point.getX() && c.getY() == point.getY()))
    return (false);
  float d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
             (b.getY() - a.getY()) * (point.getX() - a.getX());
  float d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
             (c.getY() - b.getY()) * (point.getX() - b.getX());
  float d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
             (a.getY() - c.getY()) * (point.getX() - c.getX());
  bool neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
  bool pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);
  return !(neg && pos);
}
