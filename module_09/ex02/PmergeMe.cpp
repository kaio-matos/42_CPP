/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/27 23:26:21 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **numbers) : _numbers(numbers) {}

PmergeMe::PmergeMe(const PmergeMe &value) : _numbers(value._numbers) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &value) {
	this->_numbers = value._numbers;
	return *this;
}

PmergeMe::~PmergeMe(void) {}

template <typename T>
T PmergeMe::_parse(void) {
	T result;
	char **numbers = this->_numbers;

	while (*numbers) {
		result.push_back(std::atoi(*numbers));
		numbers++;
	}
	return result;
}

template <typename T>
T PmergeMe::getUnsorted(void) {
	return this->_parse<T>();
}

std::vector<PmergeMe::ull> PmergeMe::sortAsVector(void) {
	std::vector<ull> unsorted = this->getUnsorted<std::vector<ull> >();
	this->_sort<std::vector<ull>::iterator >(unsorted.begin(), unsorted.end());
	return unsorted;
}

std::list<PmergeMe::ull> PmergeMe::sortAsList(void) {
	std::list<ull> unsorted = this->getUnsorted<std::list<ull> >();
	this->_sort<std::list<ull>::iterator >(unsorted.begin(), unsorted.end());
	return unsorted;
}

template<typename Iterator>
void PmergeMe::_sortImplementation(Iterator begin, Iterator end) {

    std::size_t size = std::distance(begin, end);
    if (size < 2) return;

    bool hasLeftover = (size % 2 != 0);

    Iterator last = hasLeftover ? moveIt(end, -1) : end;
    for (Iterator it = begin ; it != last ; it += 2) {
        if (it[1] < it[0]) {
            swapGroupIterator(it, it + 1);
		}
    }
    _sort(
        makeGroupIterator(begin, 2),
        makeGroupIterator(last, 2)
    );

    std::list<Iterator> chain;
    std::list<Pair<Iterator> > pend;
    _fillChainAndPend(begin, last, chain, pend, hasLeftover);
    _binaryInsertionSortChain(chain, pend);
    _moveFromChainToContainer(chain, begin);
}

template<typename Iterator>
void PmergeMe::_sort(Iterator first, Iterator last) {
    _sortImplementation(
        makeGroupIterator(first, 1),
        makeGroupIterator(last, 1)
    );
}

template<typename Iterator>
void PmergeMe::_fillChainAndPend(
    Iterator begin,
    Iterator end,
    typename std::list<Iterator> &chain,
    typename std::list<Pair<Iterator> > &pend,
    bool hasLeftover
) {
	chain.push_back(begin);
	chain.push_back(moveIt(begin));

    for (Iterator it = begin + 2 ; it != end ; it += 2) {
        typename std::list<Iterator>::iterator tmp = chain.insert(chain.end(), moveIt(it));
		Pair<Iterator> n = {.first = it, .chainIteratorSecond = tmp};
        pend.push_back(n);
    }

    if (hasLeftover) {
		Pair<Iterator> n = {.first = end, .chainIteratorSecond = chain.end()};
        pend.push_back(n);
    }
}

template<typename Iterator>
void PmergeMe::_moveFromChainToContainer(typename std::list<Iterator> chain, Iterator first) {
    std::vector<typename GroupIterator<Iterator>::value_type> cache;
	for (typename std::list<Iterator>::iterator it = chain.begin(); it != chain.end(); ++it) {
        typename Iterator::iterator_type begin = (*it).base();
        typename Iterator::iterator_type end = moveIt(begin, (*it).size());
        copyFromTo(begin, end, std::back_inserter(cache));
	}
    copyFromTo(cache.begin(), cache.end(), first.base());
}

template<typename Iterator>
void PmergeMe::_binaryInsertionSortChain(
    typename std::list<Iterator> &chain,
    typename std::list<Pair<Iterator> > &pend
) {
	typedef typename std::list<Iterator>::iterator ChainIterator;
	typedef typename std::list<Pair<Iterator> >::iterator PairIterator;

    static ull jacobsthalNumbers[] = {
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

    int i = 0;
    while (true) {
        ull dist = jacobsthalNumbers[i];
        if (dist >= pend.size()) break;
        PairIterator it = moveIt(pend.begin(), dist - 1);

        while (true) {
            ChainIterator insertionPoint = std::upper_bound(
                chain.begin(), it->chainIteratorSecond, it->first,
            	compare<Iterator>
            );
            chain.insert(insertionPoint, it->first);

            it = pend.erase(it);
            if (it == pend.begin()) break;
            it--;
        }
        i++;
    }

    while (!pend.empty()) {
        PairIterator it = moveIt(pend.end(), -1);
        ChainIterator insertionPoint = std::upper_bound(
            chain.begin(), it->chainIteratorSecond, it->first,
            compare<Iterator>
        );
        chain.insert(insertionPoint, it->first);
        pend.pop_back();
    }
}
