/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:11:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 09:11:28 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
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

struct Data {
  std::string name;
  unsigned int luckyNumber;
};

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(Serializer const &origin);
  ~Serializer();

  Serializer &operator=(Serializer const &origin);
};
