/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:48:41 by xq                #+#    #+#             */
/*   Updated: 2023/08/03 10:48:42 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(const int val);
  Fixed(const float val);
  Fixed(const Fixed &autre);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed(void);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _entier;
  static const int _entiercs = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
