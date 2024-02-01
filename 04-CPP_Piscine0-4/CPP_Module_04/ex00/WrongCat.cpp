/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:12:49 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 16:12:50 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
 *          CONSTRUCTORS
 * */

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  cout << GRN "[WrongCat]" W << this->_type
       << " has apeared, Meowwwwwwww! But wrongly." NC << endl;
}

WrongCat::WrongCat(WrongCat const &origin) : WrongAnimal("WrongCat") {
  *this = origin;
  cout << GRN "[WrongCat]" W << this->_type
       << " has apeared, Meowwwwwwww... but wrongly, But looks the same as "
       << origin._type << "!" NC << endl;
}

/*
 *          DESTRUCTOR
 * */

WrongCat::~WrongCat() {
  cout << RED "[WrongCat]" W << this->_type
       << " disappears, Meowwwwwwww! But wrongly." NC << endl;
}

/*
 *          COPY OPERATOR
 * */

WrongCat &WrongCat::operator=(WrongCat const &origin) {
  if (this->_type != origin._type)
    this->_type = origin._type;
  return *this;
}

/*
 *          FUNCTIONS
 * */

void WrongCat::makeSound() const {
  cout << W "[WrongCat]" << this->_type << ": Meowwwww! But wrongly." NC
       << endl;
}
