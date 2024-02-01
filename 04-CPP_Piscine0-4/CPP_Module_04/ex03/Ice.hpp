/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:56:16 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 09:56:17 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(Ice const &origin);
  ~Ice();

  Ice &operator=(Ice const &origin);

  Ice *clone() const;
  void use(ICharacter &target);
};
