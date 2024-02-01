/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:05:45 by xq                #+#    #+#             */
/*   Updated: 2023/08/09 11:02:07 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void replace(std::string &str, const std::string &s1, const std::string &s2) {
  size_t startPos = 0;
  while ((startPos = str.find(s1, startPos)) != std::string::npos) {
    str = str.substr(0, startPos) + s2 + str.substr(startPos + s1.length());
    startPos += s2.length();
  }
}

int main(int ac, char **av) {
  if (ac != 4) {
    std::cout << "\033[1;31mError: ./Sed [File] [StringToReplaceByS2] [S2]"
              << std::endl;
    return 1;
  }

  std::ifstream inf(av[1]);
  std::string s1(av[2]);
  std::string s2(av[3]);
  if (!std::string(av[1]).length()) {
    std::cout << "\033[1;31mError: File length must positive" << std::endl;
    return 1;
  } else if (!s1.length()) {
    std::cout << "\033[1;31mError: String1 length must positive" << std::endl;
    return 1;
  } else if (!inf.is_open()) {
    std::cout << "\033[1;31mError: Infile problem" << std::endl;
    return 1;
  }
  std::string name = std::string(av[1]) + ".replace";
  std::ofstream outf(name.c_str());
  if (!outf.is_open()) {
    std::cout << "\033[1;31mError: Outfile error" << std::endl;
    return 1;
  }
  std::string file((std::istreambuf_iterator<char>(inf)),
                   std::istreambuf_iterator<char>());
  inf.close();
  replace(file, s1, s2);
  outf << file;
  outf.close();
  return 0;
}
