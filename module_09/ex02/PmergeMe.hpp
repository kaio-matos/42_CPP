/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/25 23:17:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe
{

public:
	typedef unsigned long long ull;
	PmergeMe(char **numbers);
	PmergeMe(const PmergeMe &value);
	PmergeMe &operator=(const PmergeMe &value);
	~PmergeMe(void);

	std::vector<ull> sortAsVector(void);
	std::list<ull> sortAsList(void);
	template <typename T>
	T getUnsorted(void);

private:
	char **_numbers;
	template <typename T>
	T _parse(void);

	template<typename Iterator>
	void merge_insertion_sort_impl(Iterator first, Iterator last);
	template<typename Iterator>
	void merge_insertion_sort(Iterator first, Iterator last);
};

template <typename T>
void print(T begin, T end, std::string name = "")
{
	T it = begin;

	if (!name.empty())
	{
		std::cout << name;
	}

	while (it != end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

#endif
