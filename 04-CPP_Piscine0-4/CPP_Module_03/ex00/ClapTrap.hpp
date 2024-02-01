/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:36:10 by xq                #+#    #+#             */
/*   Updated: 2023/08/10 09:36:11 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap {
public:
  ClapTrap(void);
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const &clap);
  ~ClapTrap(void);
  ClapTrap &operator=(ClapTrap const &clap);
  std::string getName(void);
  unsigned int getAD(void);
  unsigned int getEP(void);
  void setEP(unsigned int);
  void setHP(unsigned int);
  void attack(const std::string &name);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  std::string _name;
  unsigned int _hp;
  unsigned int _ep;
  unsigned int _ad;
};
