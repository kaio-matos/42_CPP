/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/27 22:38:41 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

template<typename Iterator>
struct Pair {
	Iterator first;
	typename std::list<Iterator>::iterator chainIteratorSecond;
};

template<typename Iterator>
class GroupIterator;

template<typename Iterator>
Iterator moveIt(Iterator it, int n = 1) {
	Iterator next = it;
	std::advance(next, n);
	return next;
}

template<typename Iterator>
bool compare(Iterator lhs, Iterator rhs) {
    return *lhs < *rhs;
}

template<typename Iterator1, typename Iterator2>
void swapGroupIterator(GroupIterator<Iterator1> lhs, GroupIterator<Iterator2> rhs) {
    std::swap_ranges(lhs.base(), moveIt(lhs.base(), lhs.size()), rhs.base());
}

template<typename InputIt, typename OutputIt>
OutputIt copyFromTo(InputIt first, InputIt last, OutputIt dFirst) {
    for (; first != last; ++dFirst, ++first)
        *dFirst = *first;

    return dFirst;
}

template <typename T>
void print(T begin, T end, std::string name = "") {
	T it = begin;

	if (!name.empty()) {
		std::cout << name;
	}

	while (it != end) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

class PmergeMe {

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
	void _sortImplementation(Iterator first, Iterator last);
	template<typename Iterator>
	void _sort(Iterator first, Iterator last);

	template<typename Iterator>
    void _fillChainAndPend(
        Iterator begin,
        Iterator end,
        typename std::list<Iterator> &chain,
        typename std::list<Pair<Iterator> > &pend,
        bool hasLeftover
    );

    template<typename Iterator>
    void _binaryInsertionSortChain(
        typename std::list<Iterator> &chain,
        typename std::list<Pair<Iterator> > &pend
    );

    template<typename Iterator>
    void _moveFromChainToContainer(
        typename std::list<Iterator> chain,
        Iterator first
    );

};

template<typename Iterator>
class GroupIterator
{
private:
    Iterator _it;
    std::size_t _size;

public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef Iterator iterator_type;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
    typedef typename std::iterator_traits<Iterator>::pointer pointer;
    typedef typename std::iterator_traits<Iterator>::reference reference;

    GroupIterator(): _it(Iterator()), _size(0) {}
    GroupIterator(Iterator it, std::size_t size): _it(it), _size(size) {}
    GroupIterator &operator=(GroupIterator<Iterator> value) {
        _it = value._it;
        _size = value._size;
        return *this;
    }
    ~GroupIterator() {}

    iterator_type base() const {
        return _it;
    }

    std::size_t size() const {
        return _size;
    }

    reference operator*() const {
        return *moveIt(_it, _size - 1);
    }

    GroupIterator &operator++() {
        _it = moveIt(_it, _size);
        return *this;
    }

    GroupIterator &operator--() {
        _it = moveIt(_it, -_size);
        return *this;
    }

    GroupIterator &operator+=(std::size_t increment) {
        _it = moveIt(_it, _size * increment);
        return *this;
    }

    GroupIterator& operator-=(std::size_t increment) {
        _it = moveIt(_it, -(_size * increment));
        return *this;
    }

    value_type operator[](std::size_t pos) {
        return *moveIt(_it, pos * _size + _size - 1);
    }
};

template<typename Iterator1, typename Iterator2>
bool operator!=(const GroupIterator<Iterator1>& lhs,
                const GroupIterator<Iterator2>& rhs) {
    return lhs.base() != rhs.base();
}

template<typename Iterator>
GroupIterator<Iterator> operator+(GroupIterator<Iterator> it, std::size_t size) {
    return it += size;
}

template<typename Iterator>
typename GroupIterator<Iterator>::difference_type operator-(const GroupIterator<Iterator>& lhs, const GroupIterator<Iterator>& rhs) {
    return (std::distance(rhs.base(), lhs.base()) / lhs.size());
}

template<typename Iterator>
GroupIterator<Iterator> makeGroupIterator(Iterator it, std::size_t size) {
	GroupIterator<Iterator> n(it, size);
	return n;
}

template<typename Iterator>
GroupIterator<Iterator> makeGroupIterator(GroupIterator<Iterator> it, std::size_t size) {
	GroupIterator<Iterator> n(it.base(), size * it.size());
	return n;
}
#endif
