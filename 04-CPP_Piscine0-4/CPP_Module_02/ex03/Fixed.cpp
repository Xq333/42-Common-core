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

Fixed::Fixed(void) { this->_entier = 0; }

Fixed::Fixed(const int val) { this->_entier = val << this->_entiercs; }

Fixed::Fixed(const float val) {
  this->_entier = static_cast<int>(roundf(val * (1 << this->_entiercs)));
}

int Fixed::toInt(void) const { return this->_entier >> this->_entiercs; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_entier) / (1 << this->_entiercs);
}

Fixed::Fixed(const Fixed &autre) { *this = autre; }

int Fixed::getRawBits(void) const { return this->_entier; }
void Fixed::setRawBits(int const entier) { this->_entier = entier; }

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &fixed) {
  if (this != &fixed)
    this->_entier = fixed.getRawBits();
  return *this;
}
Fixed Fixed::operator+(const Fixed &fixed) const {
  return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return Fixed(this->toFloat() / fixed.toFloat());
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed) {
  o << fixed.toFloat();
  return o;
}

Fixed Fixed::operator++() {
  this->_entier++;
  return *this;
}

Fixed Fixed::operator--() {
  this->_entier--;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  this->_entier++;
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->_entier--;
  return tmp;
}

bool Fixed::operator>(const Fixed &fixed) const {
  return this->_entier > fixed._entier;
}
bool Fixed::operator<(const Fixed &fixed) const {
  return this->_entier < fixed._entier;
}
bool Fixed::operator>=(const Fixed &fixed) const {
  return this->_entier >= fixed._entier;
}
bool Fixed::operator<=(const Fixed &fixed) const {
  return this->_entier <= fixed._entier;
}
bool Fixed::operator==(const Fixed &fixed) const {
  return this->_entier == fixed._entier;
}
bool Fixed::operator!=(const Fixed &fixed) const {
  return this->_entier != fixed._entier;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a < b ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) { return a < b ? b : a; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a < b ? b : a;
}
