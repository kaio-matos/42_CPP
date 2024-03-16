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

PmergeMe::PmergeMe(char **numbers) : _numbers(numbers) {}

PmergeMe::PmergeMe(const PmergeMe &value) : _numbers(value._numbers) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &value)
{
	this->_numbers = value._numbers;
	return *this;
}

PmergeMe::~PmergeMe(void) {}

template <typename T>
T PmergeMe::_parse(void)
{
	T result;
	char **numbers = this->_numbers;

	while (*numbers)
	{
		result.push_back(std::atoi(*numbers));
		numbers++;
	}
	return result;
}

template <typename T>
T PmergeMe::getUnsorted(void)
{
	return this->_parse<T>();
}

std::vector<PmergeMe::ull> PmergeMe::sortAsVector(void)
{
	std::vector<ull> unsorted = this->getUnsorted<std::vector<ull> >();
	this->_sort(unsorted.begin(), unsorted.end());
	return unsorted;
}

std::list<PmergeMe::ull> PmergeMe::sortAsList(void)
{
	std::list<ull> unsorted = this->getUnsorted<std::list<ull> >();
	this->_sort(unsorted.begin(), unsorted.end());
	return unsorted;
}

template <typename T>
void PmergeMe::_insertionsort(T begin, T end)
{
	for (T it = begin; it != end; ++it)
	{
		T temp = it;
		std::advance(temp, 1);
		std::rotate(std::upper_bound(begin, it, *it), it, temp);
	}
}

template <typename Iterator>
void PmergeMe::_sort(Iterator begin, Iterator end)
{
	ull size = std::distance(begin, end);

	if (size <= _GROUPS_SIZE)
	{
		this->_insertionsort(begin, end);
		return;
	}

	Iterator middle = begin;
	std::advance(middle, (size / 2));

	this->_sort(begin, middle);
	this->_sort(middle, end);

	this->_merge(begin, middle, end);
}

void PmergeMe::_merge(
	std::vector<ull>::iterator start,
	std::vector<ull>::iterator mid,
	std::vector<ull>::iterator end)
{
	std::vector<ull>::iterator it = start;
	std::vector<ull>::iterator it1 = start;
	std::vector<ull>::iterator it2 = mid;
	std::vector<ull> result;

	while (it != end)
	{
		if (it1 != mid && (it2 == end || *it1 <= *it2))
		{
			result.push_back(*it1);
			it1++;
		}
		else
		{
			result.push_back(*it2);
			it2++;
		}
		it++;
	}

	it = result.begin();
	while (it != result.end())
	{
		*start = *it;
		start++;
		it++;
	}
}

void PmergeMe::_merge(
	std::list<ull>::iterator start,
	std::list<ull>::iterator mid,
	std::list<ull>::iterator end)
{
	std::list<ull>::iterator it = start;
	std::list<ull>::iterator it1 = start;
	std::list<ull>::iterator it2 = mid;
	std::list<ull> result;

	while (it != end)
	{
		if (it1 != mid && (it2 == end || *it1 <= *it2))
		{
			result.push_back(*it1);
			it1++;
		}
		else
		{
			result.push_back(*it2);
			it2++;
		}
		it++;
	}

	it = result.begin();
	while (it != result.end())
	{
		*start = *it;
		start++;
		it++;
	}
}
