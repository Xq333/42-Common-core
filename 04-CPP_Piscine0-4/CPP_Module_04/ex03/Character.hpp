/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:57:09 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 12:57:10 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  Character(string const &name);
  Character(Character const &origin);
  virtual ~Character();

  Character &operator=(Character const &origin);

  virtual string const &getName() const;

  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

protected:
  string _name;
  AMateria *_inventory[4];
};
