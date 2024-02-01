/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:39 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:23:40 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {
public:
  HumanA(std::string name, Weapon &arme);
  ~HumanA(void);
  void attack(void);

private:
  std::string _name;
  Weapon &_arme;
};
