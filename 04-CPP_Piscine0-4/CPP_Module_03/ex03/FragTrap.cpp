#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unnamed") {
  this->_hp = 100;
  this->_ep = 100;
  this->_ad = 30;
  std::cout << "\033[1;94mFragTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->_hp = 100;
  this->_ep = 100;
  this->_ad = 30;
  std::cout << "\033[1;94mFragTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
  *this = copy;
  std::cout << "\033[1;31mFragTrap " << this->_name << ", a copy of "
            << copy._name << " appeared!\033[1;0m" << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "\033[1;31mFragTrap " << this->_name << " left!\033[1;0m"
            << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &origin) {
  this->_name = origin._name;
  this->_ad = origin._ad;
  this->_hp = origin._hp;
  this->_ep = origin._ep;
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "\033[1;30mFragTrap " << this->_name << " want a high five!"
            << std::endl;
}
