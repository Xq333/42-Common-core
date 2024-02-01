/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:39 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:39 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(Dog const &origin);
  ~Dog();

  Dog &operator=(Dog const &origin);

  void makeSound() const;
};
