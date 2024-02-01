/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:45:51 by xq                #+#    #+#             */
/*   Updated: 2023/09/14 11:13:10 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed ScavTrap") {
  this->_hp = 100;
  this->_ep = 50;
  this->_ad = 20;
  std::cout << "\033[1;94mScavTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  this->_hp = 100;
  this->_ep = 50;
  this->_ad = 20;
  std::cout << "\033[1;94mScavTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other._name) {
  this->_hp = other._hp;
  this->_ep = other._ep;
  this->_ad = other._ad;
  std::cout << "\033[1;31mScavTrap " << this->_name << ", a copy of "
            << other._name << " appeared!\033[1;0m" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "\033[1;31mScavTrap " << this->_name << " left!\033[1;0m"
            << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  this->_name = other._name;
  this->_hp = other._hp;
  this->_ep = other._ep;
  this->_ad = other._ad;
  return *this;
}

void ScavTrap::attack(const std::string &name) {
  if (this->_hp == 0) {
    std::cout << "\033[1;91mScavTrap " << this->_name
              << " is dead, so he cannot attack " << name << "\033[1;0m!"
              << std::endl;
  } else if (this->_ep == 0) {
    std::cout << "\033[1;93mScavTrap " << this->_name
              << " doesn't have enough energy to attack " << name
              << "!\033[1;0m" << std::endl;
  } else {
    std::cout << "\033[1;92mScavTrap " << this->_name << " attacks " << name
              << ", causing " << this->_ad << " points of damage!\033[1;0m"
              << std::endl;
  }
}

void ScavTrap::guardGate() {
  std::cout << "\033[1;92mScavTrap " << this->_name
            << " is now in Gatekeeper mode!\033[1;0m" << std::endl;
}
