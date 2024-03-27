/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/26 21:56:04 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double toMicroseconds(clock_t &start, clock_t &end);
bool isNumber(const std::string &s);
void validateArguments(int argc, char **argv);

int main(int argc, char **argv)
{
  validateArguments(argc, argv);
  argv++;

  PmergeMe MergeSort(argv);

  clock_t start, end;

  {
    start = clock();
    std::vector<PmergeMe::ull> sortedVector = MergeSort.sortAsVector();
    end = clock();
    std::vector<PmergeMe::ull> unsortedVector = MergeSort.getUnsorted<std::vector<PmergeMe::ull> >();
    print(unsortedVector.begin(), unsortedVector.end(), "Before: ");
    print(sortedVector.begin(), sortedVector.end(), "After:  ");
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector " << toMicroseconds(start, end) << " µs" << std::endl;
  }
  {
    start = clock();
    std::list<PmergeMe::ull> sortedList = MergeSort.sortAsList();
    end = clock();

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list " << toMicroseconds(start, end) << " µs" << std::endl;
  }
  return 0;
}

double toMicroseconds(clock_t &start, clock_t &end)
{
  static const int SEC_TO_MICRO = 1e6; // 10^6
  return (static_cast<double>(end - start) / CLOCKS_PER_SEC) * SEC_TO_MICRO;
}

bool isNumber(const std::string &s)
{
  std::string::const_iterator it = s.begin();
  if ((s.at(0) == '+') && s.length() != 1)
    it++;
  while (it != s.end() && std::isdigit(*it))
    ++it;
  return !s.empty() && it == s.end();
}

void validateArguments(int argc, char **argv)
{
  if (argc <= 1)
  {
    std::cerr << "Bad arguments" << std::endl;
    exit(1);
  }
  argv++;

  while (*argv)
  {
    if (!isNumber(std::string(*argv)))
    {
      std::cerr << "Bad arguments" << std::endl;
      exit(1);
    }
    argv++;
  }
}
