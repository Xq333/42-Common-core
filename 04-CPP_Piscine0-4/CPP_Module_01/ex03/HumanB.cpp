/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:45 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:23:46 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _arme(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) {
  if (this->_arme && this->_arme->getType().length() == 0)
    std::cout << "\033[1;34m" << this->_name
              << " attacks with their invisible weapon"
              << "\033[1;0m" << std::endl;
  else if (this->_arme)
    std::cout << "\033[1;36m" << this->_name << " attacks with their "
              << this->_arme->getType() << "\033[1;0m" << std::endl;
  else
    std::cout << "\033[1;95m" << this->_name
              << " want to attack, but they have no weapon!"
              << "\033[1;0m" << std::endl;
}

void HumanB::setWeapon(Weapon &arme) { this->_arme = &arme; }
