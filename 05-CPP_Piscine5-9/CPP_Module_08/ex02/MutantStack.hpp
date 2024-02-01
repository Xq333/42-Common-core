/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:45:28 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/03 07:45:29 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <algorithm>
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack(){};
  MutantStack(MutantStack const &origin){};
  ~MutantStack(){};

  MutantStack &operator=(MutantStack const &origin){};

  typename std::stack<T>::container_type::iterator begin() {
    return std::stack<T>::c.begin();
  };

  typename std::stack<T>::container_type::iterator end() {
    return std::stack<T>::c.end();
  };

  typedef typename std::stack<T>::container_type::iterator iterator;
};
