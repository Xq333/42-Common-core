/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:48:46 by xq                #+#    #+#             */
/*   Updated: 2023/08/03 10:48:46 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
  std::cout << "\033[1;34mDefault constructor called\033[1;97m" << std::endl;
  _entier = 0;
}

Fixed::Fixed(const Fixed &autre) {
  std::cout << "\033[1;34mCopy constructor called\033[1;97m" << std::endl;
  *this = autre;
}

int Fixed::getRawBits(void) const {
  std::cout << "\033[1;32mgetRawBits member function called\033[1;97m"
            << std::endl;
  return this->_entier;
}
void Fixed::setRawBits(int const entier) { this->_entier = entier; }

Fixed::~Fixed(void) {
  std::cout << "\033[1;31mDestructor called\033[1;97m" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "\033[1;35mCopy assignment operator called\033[1;97m"
            << std::endl;
  if (this != &fixed)
    this->_entier = fixed.getRawBits();
  return *this;
}
