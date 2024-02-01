/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:09:06 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/18 18:09:07 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T> void mergeInsertSort(T &container) {
  if (container.size() <= 1)
    return;

  typename T::iterator mid = container.begin();
  std::advance(mid, container.size() / 2);
  T L(container.begin(), mid);
  T R(mid, container.end());
  mergeInsertSort(L);
  mergeInsertSort(R);

  container.clear();
  std::merge(L.begin(), L.end(), R.begin(), R.end(),
             std::back_inserter(container));
}

int main(int argc, char *argv[]) {
  if (argc < 3) {

    std::cerr << "Error" << std::endl;
    return 1;
  }
  std::vector<int> vector;
  std::list<int> list;

  for (int i = 1; i < argc; ++i) {
    int num = std::atoi(argv[i]);
    if (num <= 0) {
      std::cerr << "Error" << std::endl;
      return 1;
    }

    vector.push_back(num);
    list.push_back(num);
  }

  std::cout << "Before: ";
  for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  clock_t s1 = clock();
  mergeInsertSort(vector);
  clock_t e1 = clock();

  std::cout << "After: ";
  for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  double time1 = static_cast<double>(e1 - s1) / CLOCKS_PER_SEC * 1000.0;
  std::cout << "Time to process a range of " << vector.size()
            << " elements with std::vector: " << time1 << " us" << std::endl;

  clock_t s2 = clock();
  mergeInsertSort(list);
  clock_t e2 = clock();

  double time2 = static_cast<double>(e2 - s2) / CLOCKS_PER_SEC * 1000.0;
  std::cout << "Time to process a range of " << list.size()
            << " elements with std::list: " << time2 << " us" << std::endl;

  return 0;
}
