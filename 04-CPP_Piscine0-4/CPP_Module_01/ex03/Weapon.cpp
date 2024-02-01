/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:58 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:23:59 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType() const { return this->_type; }

void Weapon::setType(std::string str) { this->_type = str; }

Weapon::Weapon(std::string arme) : _type(arme){};
