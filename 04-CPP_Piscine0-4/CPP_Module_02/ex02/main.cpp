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
  std::cout << "\033[1;32m Subject main:\033[1;97m" << std::endl;
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << std::endl << "\033[1;35m My main:\033[1;97m" << std::endl;
  std::cout << "\033[1;34m";
  Fixed c(2);
  std::cout << "Fixed c created with value 2" << std::endl;
  Fixed d(2.3f);
  std::cout << "Fixed d created with value 2.3f" << std::endl;
  Fixed e(d - c);
  std::cout << "Fixed e ereated with value Fixed d - Fixed e" << std::endl;
  std::cout << "\033[1;95m";
  std::cout << "e++ = " << e++ << std::endl;
  std::cout << "e value is now " << e << std::endl;
  std::cout << "e-- = " << e-- << std::endl;
  std::cout << "e value is now " << e << std::endl;
  std::cout << "++e = " << ++e << std::endl;
  std::cout << "--e = " << --e << std::endl;
  std::cout << "\033[1;36m";
  std::cout << d << " > " << c << " = " << (d > c) << std::endl;
  std::cout << d << " < " << c << " = " << (d < c) << std::endl;
  std::cout << e << " + 2 = " << (e = e + 2) << std::endl;
  std::cout << e << " - 2 = " << e - 2 << std::endl;
  std::cout << e << " * 2 = " << e * 2 << std::endl;
  std::cout << e << " / 2 = " << e / 2 << std::endl;
  std::cout << e << " >= " << d << " = " << (e >= d) << std::endl;
  std::cout << e << " <= " << d << " = " << (e <= d) << std::endl;
  std::cout << e << " == " << d << " = " << (e == d) << std::endl;
  std::cout << e << " != " << d << " = " << (e != d) << std::endl;
  std::cout << "\033[1;93m";
  std::cout << "max between " << d << " and " << e << " = " << Fixed::max(d, e)
            << std::endl;
  std::cout << "max between " << e << " and " << c << " = " << Fixed::max(e, c)
            << std::endl;
  std::cout << "min between " << d << " and " << e << " = " << Fixed::min(d, e)
            << std::endl;
  std::cout << "min between " << e << " and " << c << " = " << Fixed::min(e, c)
            << std::endl;
  return 0;
}
