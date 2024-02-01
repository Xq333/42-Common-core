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
  Fixed b(a);
  Fixed c;
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  std::cout << std::endl << "\033[1;35m My main:\033[1;97m" << std::endl;
  Fixed d;
  d.setRawBits(10);
  std::cout << "Fixed d value set at 10 with setRawBits" << std::endl;
  Fixed e = d;
  Fixed f(e);
  std::cout << d.getRawBits() << std::endl;
  std::cout << e.getRawBits() << std::endl;
  std::cout << f.getRawBits() << std::endl;
  e.setRawBits(-6);
  std::cout << "Fixed e value set at -6 with setRawBits" << std::endl;
  f = e;
  std::cout << d.getRawBits() << std::endl;
  std::cout << e.getRawBits() << std::endl;
  std::cout << f.getRawBits() << std::endl;
  return 0;
}
