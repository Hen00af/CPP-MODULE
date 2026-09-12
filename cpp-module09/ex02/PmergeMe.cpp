#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) : _vec(copy._vec), _deq(copy._deq) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_vec = rhs._vec;
		_deq = rhs._deq;
	}
	return *this;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		char *endptr;
		long val = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || val < 0 || val > 2147483647)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

// ========== vector implementation ==========

void PmergeMe::mergeInsertSortVec(std::vector<int> &arr, std::size_t &step)
{
	std::vector<Element> elements;
	for (std::size_t i = 0; i < arr.size(); ++i)
		elements.push_back(Element(arr[i], i));
	sortElementsVec(elements, step);
	for (std::size_t i = 0; i < arr.size(); ++i)
		arr[i] = elements[i].value;
}

void PmergeMe::binaryInsertVec(std::vector<Element> &chain,
	const Element &element, std::size_t maxPos, std::size_t &step)
{
	std::size_t lo = 0;
	std::size_t hi = maxPos;
	while (lo < hi)
	{
		std::size_t mid = lo + (hi - lo) / 2;
		++step;
		if (chain[mid].value < element.value)
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(chain.begin() + static_cast<std::ptrdiff_t>(lo), element);
}

void PmergeMe::sortElementsVec(std::vector<Element> &arr, std::size_t &step)
{
	if (arr.size() <= 1)
		return;

	// Keep each pair linked by identity, even when values are equal.
	std::vector<Element> largers;
	std::vector<Element> smallers;
	for (std::size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		++step;
		if (arr[i].value > arr[i + 1].value)
		{
			largers.push_back(arr[i]);
			smallers.push_back(arr[i + 1]);
		}
		else
		{
			largers.push_back(arr[i + 1]);
			smallers.push_back(arr[i]);
		}
	}
	const std::vector<Element> partners(largers);
	sortElementsVec(largers, step);

	std::vector<Element> pending;
	for (std::size_t i = 0; i < largers.size(); ++i)
	{
		std::size_t j = 0;
		while (partners[j].id != largers[i].id)
			++j;
		pending.push_back(smallers[j]);
	}
	// The unpaired element is the final pending item, with no upper bound.
	if (arr.size() % 2 != 0)
		pending.push_back(arr.back());

	std::vector<Element> chain(largers);
	chain.insert(chain.begin(), pending[0]);

	// One-based pending order: 1, 3, 2, 5, 4, 11, 10, ..., 6, ...
	std::size_t previous = 1;
	std::size_t boundary = 3;
	while (previous < pending.size())
	{
		const std::size_t end = boundary < pending.size() ? boundary : pending.size();
		for (std::size_t k = end; k > previous; --k)
		{
			const std::size_t idx = k - 1;
			std::size_t maxPos = chain.size();
			if (idx < largers.size())
			{
				maxPos = 0;
				while (chain[maxPos].id != largers[idx].id)
					++maxPos;
			}
			// Exclude the partner: pending[idx] <= its partner is already known.
			binaryInsertVec(chain, pending[idx], maxPos, step);
		}
		if (end == pending.size())
			break;
		// Saturate at the pending size to avoid Jacobsthal arithmetic overflow.
		const std::size_t remaining = pending.size() - boundary;
		const std::size_t next = previous > remaining / 2
			? pending.size() : boundary + 2 * previous;
		previous = boundary;
		boundary = next;
	}
	arr.swap(chain);
}

// ========== deque implementation ==========

void PmergeMe::mergeInsertSortDeq(std::deque<int> &arr, std::size_t &step)
{
	std::deque<Element> elements;
	for (std::size_t i = 0; i < arr.size(); ++i)
		elements.push_back(Element(arr[i], i));
	sortElementsDeq(elements, step);
	for (std::size_t i = 0; i < arr.size(); ++i)
		arr[i] = elements[i].value;
}

void PmergeMe::binaryInsertDeq(std::deque<Element> &chain,
	const Element &element, std::size_t maxPos, std::size_t &step)
{
	std::size_t lo = 0;
	std::size_t hi = maxPos;
	while (lo < hi)
	{
		std::size_t mid = lo + (hi - lo) / 2;
		++step;
		if (chain[mid].value < element.value)
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(chain.begin() + static_cast<std::ptrdiff_t>(lo), element);
}

void PmergeMe::sortElementsDeq(std::deque<Element> &arr, std::size_t &step)
{
	if (arr.size() <= 1)
		return;

	// Keep each pair linked by identity, even when values are equal.
	std::deque<Element> largers;
	std::deque<Element> smallers;
	for (std::size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		++step;
		if (arr[i].value > arr[i + 1].value)
		{
			largers.push_back(arr[i]);
			smallers.push_back(arr[i + 1]);
		}
		else
		{
			largers.push_back(arr[i + 1]);
			smallers.push_back(arr[i]);
		}
	}
	const std::deque<Element> partners(largers);
	sortElementsDeq(largers, step);

	std::deque<Element> pending;
	for (std::size_t i = 0; i < largers.size(); ++i)
	{
		std::size_t j = 0;
		while (partners[j].id != largers[i].id)
			++j;
		pending.push_back(smallers[j]);
	}
	// The unpaired element is the final pending item, with no upper bound.
	if (arr.size() % 2 != 0)
		pending.push_back(arr.back());

	std::deque<Element> chain(largers);
	chain.insert(chain.begin(), pending[0]);

	// One-based pending order: 1, 3, 2, 5, 4, 11, 10, ..., 6, ...
	std::size_t previous = 1;
	std::size_t boundary = 3;
	while (previous < pending.size())
	{
		const std::size_t end = boundary < pending.size() ? boundary : pending.size();
		for (std::size_t k = end; k > previous; --k)
		{
			const std::size_t idx = k - 1;
			std::size_t maxPos = chain.size();
			if (idx < largers.size())
			{
				maxPos = 0;
				while (chain[maxPos].id != largers[idx].id)
					++maxPos;
			}
			// Exclude the partner: pending[idx] <= its partner is already known.
			binaryInsertDeq(chain, pending[idx], maxPos, step);
		}
		if (end == pending.size())
			break;
		// Saturate at the pending size to avoid Jacobsthal arithmetic overflow.
		const std::size_t remaining = pending.size() - boundary;
		const std::size_t next = previous > remaining / 2
			? pending.size() : boundary + 2 * previous;
		previous = boundary;
		boundary = next;
	}
	arr.swap(chain);
}

// ========== Public interface ==========

void PmergeMe::printBefore() const
{
	std::cout << "Before:";
	for (std::size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After:";
	for (std::size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::sort()
{
	printBefore();

	// Sort with vector
	std::vector<int> vecCopy(_vec);
	std::size_t stepVec = 0;
	clock_t startVec = clock();
	mergeInsertSortVec(vecCopy, stepVec);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	// Sort with deque
	std::deque<int> deqCopy(_deq);
	std::size_t stepDeq = 0;
	clock_t startDeq = clock();
	mergeInsertSortDeq(deqCopy, stepDeq);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	_vec = vecCopy;
	_deq = deqCopy;

	printAfter();
	std::cout << "Time to process a range of " << vecCopy.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deqCopy.size()
		<< " elements with std::deque : " << timeDeq << " us" << std::endl;
	std::cout << "Steps (element comparisons) with std::vector : " << stepVec << std::endl;
	std::cout << "Steps (element comparisons) with std::deque : " << stepDeq << std::endl;
}
