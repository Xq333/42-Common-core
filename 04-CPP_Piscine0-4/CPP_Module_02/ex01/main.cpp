/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:48:13 by xq                #+#    #+#             */
/*   Updated: 2023/08/03 10:48:15 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  std::cout << "\033[1;34m";
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);
  Fixed const e(-10.10f);
  std::cout << "\033[1;35m";
  a = Fixed(1234.4321f);
  std::cout << "\033[1;32m";
  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  std::cout << "e is " << e << std::endl;
  std::cout << "\033[1;93m";
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  std::cout << "e is " << e.toInt() << " as integer" << std::endl;
  std::cout << "\033[1;31m";
  return 0;
}
