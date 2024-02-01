/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:00:06 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 09:00:07 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
public:
  Point(void);
  Point(const float x, const float y);
  Point(const Point &autre);
  float getX(void) const;
  float getY(void) const;
  ~Point(void);
  Point &operator=(const Point &point);

private:
  const Fixed _x;
  const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
