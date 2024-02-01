/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:26:07 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:26:08 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>

class ShruberryCreationForm : public AForm {
public:
  ShruberryCreationForm();
  ShruberryCreationForm(std::string const &_target);
  virtual ~ShruberryCreationForm();

  void execute(Bureaucrat const &executor) const;

private:
  ShruberryCreationForm(ShruberryCreationForm const &origin);

  ShruberryCreationForm &operator=(ShruberryCreationForm const &origin);

  std::string const _target;
};
