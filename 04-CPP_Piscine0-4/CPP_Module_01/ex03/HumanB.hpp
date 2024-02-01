/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:49 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:23:51 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB(void);
  void attack(void);
  void setWeapon(Weapon &arme);

private:
  std::string _name;
  Weapon *_arme;
};
