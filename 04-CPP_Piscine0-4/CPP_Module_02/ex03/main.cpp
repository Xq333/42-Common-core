/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:48:13 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 13:40:19 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
  Point a(1.0, 1.0);
  Point b(5.0, 1.0);
  Point c(3.0, 5.0);
  Point point(3.0, 2.0);
  Point point1(0.0, 0.0);
  Point point2(3.0, 5.0);
  Point point3(3, 1.0);

  std::cout << "\033[1;34mTriangle vertices:" << std::endl;
  std::cout << "\033[1;33mPoint a: (" << a.getX() << ", " << a.getY() << ")"
            << std::endl;
  std::cout << "Point b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
  std::cout << "Point c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
  std::cout << "\033[1;35mPoint to evaluate: (" << point.getX() << ", "
            << point.getY() << ")" << std::endl;
  if (bsp(a, b, c, point)) {
    std::cout << "\033[1;32mThe point is inside the triangle." << std::endl;
  } else {
    std::cout << "\033[1;31mThe point is not inside the triangle." << std::endl;
  }
  std::cout << "\033[1;35mPoint to evaluate: (" << point1.getX() << ", "
            << point1.getY() << ")" << std::endl;
  if (bsp(a, b, c, point1)) {
    std::cout << "\033[1;32mThe point is inside the triangle." << std::endl;
  } else {
    std::cout << "\033[1;31mThe point is not inside the triangle." << std::endl;
  }
  std::cout << "\033[1;35mPoint to evaluate: (" << point2.getX() << ", "
            << point2.getY() << ")" << std::endl;
  if (bsp(a, b, c, point2)) {
    std::cout << "\033[1;32mThe point is inside the triangle." << std::endl;
  } else {
    std::cout << "\033[1;31mThe point is not inside the triangle." << std::endl;
  }
  std::cout << "\033[1;35mPoint to evaluate: (" << point3.getX() << ", "
            << point3.getY() << ")" << std::endl;
  if (bsp(a, b, c, point3)) {
    std::cout << "\033[1;32mThe point is inside the triangle." << std::endl;
  } else {
    std::cout << "\033[1;31mThe point is not inside the triangle." << std::endl;
  }
  return 0;
}
