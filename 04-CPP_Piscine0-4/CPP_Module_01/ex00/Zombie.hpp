/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:46:10 by xq                #+#    #+#             */
/*   Updated: 2023/07/31 20:46:11 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
  Zombie(void);
  Zombie(std::string nom);
  ~Zombie(void);
  void announce(void);

private:
  std::string _nom;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
