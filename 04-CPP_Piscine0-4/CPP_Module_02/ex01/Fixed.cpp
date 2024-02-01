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

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->_entier = 0;
}

Fixed::Fixed(const int val) {
  std::cout << "Int constructor called" << std::endl;
  this->_entier = val << this->_entiercs;
}

Fixed::Fixed(const float val) {
  std::cout << "Float constructor called" << std::endl;
  this->_entier = static_cast<int>(roundf(val * (1 << this->_entiercs)));
}

int Fixed::toInt(void) const { return this->_entier >> this->_entiercs; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_entier) / (1 << this->_entiercs);
}

Fixed::Fixed(const Fixed &autre) {
  std::cout << "Copy constructor called" << std::endl;
  *this = autre;
}

int Fixed::getRawBits(void) const { return this->_entier; }
void Fixed::setRawBits(int const entier) { this->_entier = entier; }

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed)
    this->_entier = fixed.getRawBits();
  return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed) {
  o << fixed.toFloat();
  return o;
}
