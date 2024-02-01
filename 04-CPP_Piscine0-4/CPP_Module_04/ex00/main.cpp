/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:44 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:45 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  cout << BLU "---===---===--- SUBJECT MAIN ---===---===---" NC << endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete i;
  delete j;
  delete meta;
  cout << BLU "---===---===--- MY MAIN ---===---===---" NC << endl;
  const Animal *olddog = new Dog();
  const Animal *dog(olddog);
  const Animal *animal = new Animal();
  const Animal *cat = new Cat();
  const WrongAnimal *WrongA = new WrongAnimal();
  const WrongAnimal *WrongC = new WrongCat();
  cout << dog->getType() << " is the type of the dog" << endl;
  cout << animal->getType() << " is the type of the animal" << endl;
  cout << cat->getType() << " is the type of the cat" << endl;
  cout << WrongA->getType() << " is the type of the future dog" << endl;
  cout << WrongC->getType() << " is the type of the cat" << endl;
  dog->makeSound();
  animal->makeSound();
  cat->makeSound();
  WrongA->makeSound();
  WrongC->makeSound();
  delete WrongC;
  delete WrongA;
  delete cat;
  delete animal;
  delete dog;

  return 0;
}
