/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:53:02 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:53:03 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define RED "\033[1;31m" // FOR DESTRUCTORS
#define GRN "\033[1;32m" // FOR CONSTRUCTORS
#define YEL "\033[1;33m" // FOR ERRORS
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define W "\033[1;97m"
#define NC "\033[1;0m"
using std::cout;
using std::endl;
using std::string;

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(std::string const type);
  WrongAnimal(WrongAnimal const &origin);
  virtual ~WrongAnimal();

  WrongAnimal &operator=(WrongAnimal const &origin);

  void makeSound() const;
  string getType() const;

protected:
  std::string _type;
};
