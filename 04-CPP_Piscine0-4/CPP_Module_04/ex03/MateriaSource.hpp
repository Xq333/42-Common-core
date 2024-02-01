/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:26:09 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 13:26:10 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(MateriaSource const &origin);
  ~MateriaSource();

  MateriaSource &operator=(MateriaSource const &origin);

  void learnMateria(AMateria *m);
  AMateria *createMateria(string const &type);

protected:
  AMateria *_inventory[4];
};
