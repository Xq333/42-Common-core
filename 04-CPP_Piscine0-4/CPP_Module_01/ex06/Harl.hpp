/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:25 by xq                #+#    #+#             */
/*   Updated: 2023/08/09 14:34:26 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
public:
  Harl(std::string &str);
  ~Harl(void);
  void complain(void);
  int filter;

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
};
