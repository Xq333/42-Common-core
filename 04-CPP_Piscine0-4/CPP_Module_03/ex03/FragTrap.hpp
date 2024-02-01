#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(FragTrap const &copy);
  ~FragTrap();
  FragTrap &operator=(FragTrap const &origin);
  void highFivesGuys();
};
