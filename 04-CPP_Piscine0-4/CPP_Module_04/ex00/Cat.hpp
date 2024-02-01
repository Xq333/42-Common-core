/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:30:19 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 15:30:20 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(Cat const &origin);
  ~Cat();

  Cat &operator=(Cat const &origin);

  void makeSound() const;
};
