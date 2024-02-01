/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:56:20 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 09:56:20 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(Cure const &origin);
  ~Cure();

  Cure &operator=(Cure const &origin);

  Cure *clone() const;
  void use(ICharacter &target);
};
