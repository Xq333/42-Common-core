/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 08:59:59 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 11:52:07 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point) {
  if (this != &point) {
    const_cast<Fixed &>(this->_x) = point._x;
    const_cast<Fixed &>(this->_y) = point._y;
  }
  return *this;
}

Point::~Point(void) {}

float Point::getX(void) const { return _x.toFloat(); }

float Point::getY(void) const { return _y.toFloat(); }
