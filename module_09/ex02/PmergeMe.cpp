/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/09 22:15:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **numbers): _numbers(numbers) {}

PmergeMe::PmergeMe(const PmergeMe &value) {
	*this = value;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &value) {
	*this = value;
	return *this;
}

PmergeMe::~PmergeMe(void) {}


template<typename T>
T PmergeMe::_parse(void) {
	T resullt;
	char **numbers = this->_numbers;

	while (*numbers) {
		resullt.push_back(std::atoi(*numbers));
		numbers++;
	}
	return resullt;
}

template<typename T>
T PmergeMe::getUnsorted(void) {
	return this->_parse<T>();
}

std::vector<PmergeMe::ull> PmergeMe::sortAsVector(void) {
	std::vector<ull> sorted = this->_vector_mergesort(this->getUnsorted<std::vector<ull> >());
	return sorted;
}

std::list<PmergeMe::ull> PmergeMe::sortAsList(void) {
	std::list<ull> sorted = this->_list_mergesort(this->getUnsorted<std::list<ull> >());
	return sorted;
}

std::vector<PmergeMe::ull> PmergeMe::_vector_mergesort(std::vector<ull> vector) {
	ull size = vector.size();

	if (size == 1) {
		return vector;
	}

	std::vector<ull> sorted1;
	std::vector<ull> sorted2;
	std::vector<ull>::iterator begin = vector.begin();
	std::vector<ull>::iterator middle = begin + size / 2;
	std::vector<ull>::iterator end = vector.end();

	std::copy(begin, middle, back_inserter(sorted1));
	std::copy(middle, end, back_inserter(sorted2));

	sorted1 = this->_vector_mergesort(sorted1);
	sorted2 = this->_vector_mergesort(sorted2);

	return this->_merge(sorted1, sorted2);
}

std::list<PmergeMe::ull> PmergeMe::_list_mergesort(std::list<ull> list) {
	ull size = list.size();

	if (size == 1) {
		return list;
	}

	std::list<ull> sorted1;
	std::list<ull> sorted2;
	std::list<ull>::iterator begin = list.begin();
	std::list<ull>::iterator middle = list.begin();
	std::list<ull>::iterator end = list.end();
 	std::advance(middle, std::distance(begin, end) / 2);

	std::copy(begin, middle, back_inserter(sorted1));
	std::copy(middle, end, back_inserter(sorted2));

	sorted1 = this->_list_mergesort(sorted1);
	sorted2 = this->_list_mergesort(sorted2);
	return this->_merge<std::list<ull> >(sorted1, sorted2);
}


template<typename T>
T PmergeMe::_merge(T a, T b) {
	T temp;

	while (!a.empty() && !b.empty()) {

		if (*a.begin() > *b.begin()) {
			temp.push_back(*b.begin());
			b.erase(b.begin());
		} else {
			temp.push_back(*a.begin());
			a.erase(a.begin());
		}
	}

	while (!a.empty()) {
		temp.push_back(*a.begin());
		a.erase(a.begin());
	}

	while (!b.empty()) {
		temp.push_back(*b.begin());
		b.erase(b.begin());
	}

	return temp;
}
