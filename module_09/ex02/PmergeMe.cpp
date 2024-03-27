/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/26 21:02:57 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <iterator>

template<typename Iterator>
Iterator _next(Iterator it, int n = 1) {
	Iterator next = it;
	std::advance(next, n);
	return next;
}

template<typename Iterator>
void printIt(std::string name, Iterator start, Iterator end) {
	std::cout << name << "\n";
	for (Iterator it = start; it != end; std::advance(it, 1)) {
		std::cout << **it << ", ";
	}
	std::cout << "\n" << std::endl;
}

template<typename Iterator>
void printItPair(std::string name, Iterator start, Iterator end) {
	int i = 0;
	std::cout << name << "\n";
	for (Iterator it = start; it != end; std::advance(it, 1)) {
		if (i % 2 == 0) {
			std::cout << "[" << *it->value << ", ";
		}
		else if (i % 2 != 0) {
			std::cout << *it->value << "]";
		}
		i++;
	}
	std::cout << "\n" << std::endl;
}



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

template<class InputIt, class OutputIt>
OutputIt mmove(InputIt first, InputIt last, OutputIt d_first)
{
    for (; first != last; ++d_first, ++first)
        *d_first = *first;

    return d_first;
}

std::vector<PmergeMe::ull> PmergeMe::sortAsVector(void)
{
	std::vector<ull> unsorted = this->getUnsorted<std::vector<ull> >();
	this->merge_insertion_sort<std::vector<ull>::iterator >(unsorted.begin(), unsorted.end());
	return unsorted;
}


std::list<PmergeMe::ull> PmergeMe::sortAsList(void)
{
	std::list<ull> unsorted = this->getUnsorted<std::list<ull> >();
	this->merge_insertion_sort<std::list<ull>::iterator >(unsorted.begin(), unsorted.end());
	return unsorted;
}

template<typename Iterator>
class group_iterator
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

        group_iterator(): _it(Iterator()), _size(0) {};

        group_iterator(Iterator it, std::size_t size):
            _it(it),
            _size(size)
        {}

        iterator_type base() const
        {
            return _it;
        }

        std::size_t size() const
        {
            return _size;
        }

        reference operator*() const
        {
            return *_next(_it, _size - 1);
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        group_iterator& operator++()
        {
            _it = _next(_it, _size);
            return *this;
        }

        group_iterator operator++(int)
        {
            group_iterator tmp = *this;
            operator++();
            return tmp;
        }

        group_iterator& operator--()
        {
            _it = _next(_it, -_size);
            return *this;
        }

        group_iterator operator--(int)
        {
            group_iterator tmp = *this;
            operator--();
            return tmp;
        }

        group_iterator& operator+=(std::size_t increment)
        {
            _it = _next(_it, _size * increment);
            return *this;
        }

        group_iterator& operator-=(std::size_t increment)
        {
            _it = _next(_it, -(_size * increment));
            return *this;
        }

        ////////////////////////////////////////////////////////////
        // Elements access operators

        value_type operator[](std::size_t pos)
        {
            return *_next(_it, pos * _size + _size - 1);
        }

        value_type operator[](std::size_t pos) const
        {
            return *_next(_it, pos * _size + _size - 1);
        }
};

template<typename Iterator>
bool compare(Iterator lhs, Iterator rhs)
{
    return *lhs < *rhs;
}

template<typename Iterator1, typename Iterator2>
void iter_swap(group_iterator<Iterator1> lhs, group_iterator<Iterator2> rhs)
{
    std::swap_ranges(lhs.base(), _next(lhs.base(), lhs.size()), rhs.base());
}

template<typename Iterator1, typename Iterator2>
bool operator==(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() == rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator!=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() != rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() < rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() <= rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() > rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base >= rhs.base();
}

template<typename Iterator>
group_iterator<Iterator> operator+(group_iterator<Iterator> it, std::size_t size)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator+(std::size_t size, group_iterator<Iterator> it)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator-(group_iterator<Iterator> it, std::size_t size)
{
    return it -= size;
}

template<typename Iterator>
typename group_iterator<Iterator>::difference_type operator-(const group_iterator<Iterator>& lhs, const group_iterator<Iterator>& rhs)
{
    return (std::distance(rhs.base(), lhs.base()) / lhs.size());
}

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(Iterator it, std::size_t size)
{
	group_iterator<Iterator> n(it, size);
	return n;
}

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(group_iterator<Iterator> it, std::size_t size)
{
	group_iterator<Iterator> n(it.base(), size * it.size());
	return n;
}


template<typename RandomAccessIterator>
struct node
{
	RandomAccessIterator it;
	typename std::list<RandomAccessIterator>::iterator next;
};

template<typename RandomAccessIterator>
void PmergeMe::merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last)
{
    // Cache all the differences between a Jacobsthal number and its
    // predecessor that fit in 64 bits, starting with the difference
    // between the Jacobsthal numbers 4 and 3 (the previous ones are
    // unneeded)
    static ull jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    std::size_t size = std::distance(first, last);
    if (size < 2) return;

    bool has_stray = (size % 2 != 0);

    RandomAccessIterator end = has_stray ? _next(last, -1) : last;
    for (RandomAccessIterator it = first ; it != end ; it += 2) {
        if (it[1] < it[0]) {
            iter_swap(it, it + 1);
		}
    }

    merge_insertion_sort(
        make_group_iterator(first, 2),
        make_group_iterator(end, 2)
    );


	typedef typename std::list<RandomAccessIterator>::iterator ChainIterator;
	typedef typename std::list<node<RandomAccessIterator> >::iterator NodeIterator;

    std::list<RandomAccessIterator> chain;
	chain.push_back(first);
	chain.push_back(_next(first));
    std::list<node<RandomAccessIterator> > pend;

    for (RandomAccessIterator it = first + 2 ; it != end ; it += 2) {
        ChainIterator tmp = chain.insert(chain.end(), _next(it));
		node<RandomAccessIterator> n = {.it = it, .next = tmp};
        pend.push_back(n);
    }

    if (has_stray) {
		node<RandomAccessIterator> n = {.it = end, .next = chain.end()};
        pend.push_back(n);
    }

    for (int k = 0 ; ; ++k)
    {
        ull dist = jacobsthal_diff[k];
        if (dist >= pend.size()) break;
        NodeIterator it = pend.begin();
        std::advance(it, dist);

        while (true)
        {
            ChainIterator insertion_point = std::upper_bound(
                chain.begin(), it->next, it->it,
            	compare<RandomAccessIterator>
            );
            chain.insert(insertion_point, it->it);

            it = pend.erase(it);
            if (it == pend.begin()) break;
            --it;
        }
    }

    while (not pend.empty())
    {
        NodeIterator it = _next(pend.end(), -1);
        ChainIterator insertion_point = std::upper_bound(
            chain.begin(), it->next, it->it,
            compare<RandomAccessIterator>
        );
        chain.insert(insertion_point, it->it);
        pend.pop_back();
    }

    std::vector<typename group_iterator<RandomAccessIterator>::value_type> cache;
    cache.reserve(size);

	for (ChainIterator __begin = chain.begin(), __end = chain.end(); __begin != __end; ++__begin)
	{
		RandomAccessIterator we = *__begin;
        typename RandomAccessIterator::iterator_type begin = we.base();
        typename RandomAccessIterator::iterator_type end = _next(begin, we.size());
        mmove(begin, end, std::back_inserter(cache));
	}
    mmove(cache.begin(), cache.end(), first.base());
}

template<
    typename RandomAccessIterator
>
void PmergeMe::merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    merge_insertion_sort_impl(
        make_group_iterator(first, 1),
        make_group_iterator(last, 1)
    );
}
