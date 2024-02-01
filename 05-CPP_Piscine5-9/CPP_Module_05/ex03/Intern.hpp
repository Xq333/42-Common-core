/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:37:29 by xq                #+#    #+#             */
/*   Updated: 2023/09/26 14:37:29 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
  public:
    Intern();
    virtual ~Intern();

    AForm *makeForm(std::string const name, std::string const target);
  private:
    Intern(Intern const &origin);

    Intern &operator=(Intern const &origin);
};
