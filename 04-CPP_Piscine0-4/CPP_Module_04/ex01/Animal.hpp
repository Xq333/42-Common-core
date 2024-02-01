/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:22 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:26 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Brain.hpp"
#include <iostream>
#define RED "\033[1;31m" // FOR DESTRUCTORS
#define GRN "\033[1;32m" // FOR CONSTRUCTORS
#define YEL "\033[1;33m" // FOR ERRORS
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define W "\033[1;97m"
#define NC "\033[1;0m"
#define I "\033[1;3m"
#define U "\033[1;4m"
using std::cout;
using std::endl;
using std::string;

class Animal {
public:
  Animal();
  Animal(std::string const type);
  Animal(Animal const &origin);
  virtual ~Animal();

  Animal &operator=(Animal const &origin);

  virtual void makeSound() const;
  string getType() const;

protected:
  std::string _type;
};
