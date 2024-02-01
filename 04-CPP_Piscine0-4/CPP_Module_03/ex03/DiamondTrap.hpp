#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap const &origin);
  ~DiamondTrap();
  DiamondTrap &operator=(DiamondTrap const &origin);
  using ScavTrap::attack;
  void whoAmI();

private:
  std::string _name;
};
