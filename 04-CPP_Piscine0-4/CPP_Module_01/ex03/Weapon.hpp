/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:24:04 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:24:04 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon {
public:
  Weapon(void);
  Weapon(std::string arme);
  ~Weapon(void);
  const std::string &getType() const;
  void setType(std::string str);

private:
  std::string _type;
};
