/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:31:43 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/09/18 14:27:37 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  std::cout << "My tests:" << std::endl;
  ICharacter *character = new Character("Pedro");
  ICharacter *target = new Character("Brandon");
  AMateria *ice = new Ice();
  MateriaSource materiaSource;
  materiaSource.learnMateria(new Ice());
  materiaSource.learnMateria(new Cure());
  character->equip(ice);
  character->equip(materiaSource.createMateria("cure"));
  std::cout << character->getName() << " uses Materias:" << std::endl;
  character->use(0, *target);
  character->use(1, *target);
  character->unequip(0);
  std::cout << "Using an unassigned slot:" << std::endl;
  character->use(2, *target);
  character->equip(materiaSource.createMateria("ice"));
  character->equip(materiaSource.createMateria("cure"));
  std::cout << "Equipping beyond capacity:" << std::endl;
  character->equip(materiaSource.createMateria("ice"));
  ICharacter *copiedCharacter = character;
  std::cout << "Copied character uses Materias:" << std::endl;
  copiedCharacter->use(0, *target);
  copiedCharacter->use(1, *target);

  delete ice;
  delete target;
  delete character;

  return (0);
}
