/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/12 22:30:03 by kmatos-s         ###   ########.fr       */
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
#include <iterator> // for back_inserter

class PmergeMe {

public:
	typedef unsigned long long  ull;
	PmergeMe(char **numbers);
	PmergeMe(const PmergeMe &value);
	PmergeMe &operator=(const PmergeMe &value);
	~PmergeMe(void);

	std::vector<ull>       sortAsVector(void);
	std::list<ull>         sortAsList(void);
	template<typename T> T getUnsorted(void);

private:
	char ** _numbers;
	template<typename T> T _parse(void);
	template<typename T> T _merge(T vector1, T vector2);
	std::vector<ull>       _vector_mergesort(std::vector<ull> vector);
	std::list<ull>         _list_mergesort(std::list<ull> list);
};

#endif
