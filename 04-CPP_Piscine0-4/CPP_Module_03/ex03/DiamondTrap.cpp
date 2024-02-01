#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap() {
  this->_name = "Unnamed_clap_name";
  this->FragTrap::_hp = 100;
  this->ScavTrap::_ep = 50;
  this->FragTrap::_ad = 30;
  std::cout << "\033[1;94mDiamondTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  this->_name = name;
  this->FragTrap::_hp = 100;
  this->ScavTrap::_ep = 50;
  this->FragTrap::_ad = 30;
  std::cout << "\033[1;94mDiamondTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
  *this = copy;
  std::cout << "\033[1;31mDiamondTrap " << this->_name << ", a copy of "
            << copy._name << " appeared!\033[1;0m" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "\033[1;31mDiamondTrap " << this->_name << " left!\033[1;0m"
            << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &origin) {
  this->_name = origin._name;
  this->FragTrap::_hp = origin.FragTrap::_hp;
  this->ScavTrap::_ep = origin.ScavTrap::_ep;
  this->FragTrap::_ad = origin.FragTrap::_ad;
  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "\033[1;29mWho am i? DiamondTrap " << this->_name
            << " and ClapTrap " << this->ClapTrap::_name << std::endl;
}
