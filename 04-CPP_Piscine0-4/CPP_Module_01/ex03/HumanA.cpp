/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:28 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:23:28 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arme) : _name(name), _arme(arme) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {
  if (this->_arme.getType().length() == 0)
    std::cout << "\033[1;34m" << this->_name
              << " attacks with their invisible weapon"
              << "\033[1;0m" << std::endl;
  else
    std::cout << "\033[1;36m" << this->_name << " attacks with their "
              << this->_arme.getType() << "\033[1;0m" << std::endl;
}
