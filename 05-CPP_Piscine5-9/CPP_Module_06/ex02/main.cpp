/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:26:48 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 08:26:49 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
  srand(std::time(0));
  if (rand() % 3 == 0)
    return new A();
  else if (rand() % 3 == 1)
    return new B;
  return new C;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << MAG "[Base] " W " Base is A!" NC << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << MAG "[Base] " W " Base is B!" NC << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << MAG "[Base] " W " Base is C!" NC << std::endl;
}

void identify(Base &p) {
  try {
    static_cast<void>(dynamic_cast<A &>(p));
    std::cout << MAG "[Base] " W " Base is A!" NC << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    static_cast<void>(dynamic_cast<B &>(p));
    std::cout << MAG "[Base] " W " Base is B!" NC << std::endl;
    return;

  } catch (std::exception &e) {
  }
  try {
    static_cast<void>(dynamic_cast<C &>(p));
    std::cout << MAG "[Base] " W " Base is C!" NC << std::endl;
    return;

  } catch (std::exception &e) {
  }
}

int main() {
  Base *b;
  b = generate();
  identify(b);
  identify(*b);
  delete b;
  return 0;
}
