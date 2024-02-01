/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:25:39 by xq                #+#    #+#             */
/*   Updated: 2023/09/25 08:25:40 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string const &_target);
  virtual ~RobotomyRequestForm();

  void execute(Bureaucrat const &executor) const;

private:
  RobotomyRequestForm(RobotomyRequestForm const &origin);

  RobotomyRequestForm &operator=(RobotomyRequestForm const &origin);

  std::string const _target;
};
