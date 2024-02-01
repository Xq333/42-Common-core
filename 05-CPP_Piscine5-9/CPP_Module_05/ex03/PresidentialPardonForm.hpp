/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:25:33 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:25:34 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const &_target);
  virtual ~PresidentialPardonForm();

  void execute(Bureaucrat const &executor) const;

private:
  PresidentialPardonForm(PresidentialPardonForm const &origin);

  PresidentialPardonForm &operator=(PresidentialPardonForm const &origin);

  std::string const _target;
};
