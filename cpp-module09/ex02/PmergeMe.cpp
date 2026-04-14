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

size_t PmergeMe::jacobsthal(size_t n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	size_t prev2 = 0;
	size_t prev1 = 1;
	for (size_t i = 2; i <= n; i++)
	{
		size_t curr = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}

// ========== Vector implementation ==========

void PmergeMe::binaryInsertVec(std::vector<int> &chain, int value, size_t maxPos)
{
	size_t lo = 0;
	size_t hi = maxPos;
	if (hi > chain.size())
		hi = chain.size();
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (chain[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(chain.begin() + static_cast<long>(lo), value);
}

void PmergeMe::mergeInsertSortVec(std::vector<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;

	// Step 1: Form pairs and compare
	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = (n % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
		straggler = arr[n - 1];

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Recursively sort by larger element
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);
	mergeInsertSortVec(largers);

	// Reorder pairs to match sorted largers
	std::vector<int> smallers;
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largers[i])
			{
				smallers.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	// Step 3: Build main chain from sorted largers, insert first smaller
	std::vector<int> chain(largers);
	chain.insert(chain.begin(), smallers[0]);

	// Step 4: Insert remaining smallers using Jacobsthal sequence
	std::vector<bool> inserted(smallers.size(), false);
	inserted[0] = true;

	size_t jIdx = 2;
	while (true)
	{
		size_t jVal = jacobsthal(jIdx);
		size_t prevJ = jacobsthal(jIdx - 1);
		if (prevJ >= smallers.size())
			break;
		size_t end = jVal;
		if (end > smallers.size())
			end = smallers.size();
		for (size_t k = end; k > prevJ; k--)
		{
			size_t idx = k - 1;
			if (idx < smallers.size() && !inserted[idx])
			{
				binaryInsertVec(chain, smallers[idx], chain.size());
				inserted[idx] = true;
			}
		}
		jIdx++;
	}

	// Insert any remaining
	for (size_t i = 0; i < smallers.size(); i++)
	{
		if (!inserted[i])
			binaryInsertVec(chain, smallers[i], chain.size());
	}

	// Step 5: Insert straggler
	if (hasStraggler)
		binaryInsertVec(chain, straggler, chain.size());

	arr = chain;
}

// ========== Deque implementation ==========

void PmergeMe::binaryInsertDeq(std::deque<int> &chain, int value, size_t maxPos)
{
	size_t lo = 0;
	size_t hi = maxPos;
	if (hi > chain.size())
		hi = chain.size();
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (chain[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert(chain.begin() + static_cast<long>(lo), value);
}

void PmergeMe::mergeInsertSortDeq(std::deque<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = (n % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
		straggler = arr[n - 1];

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);
	mergeInsertSortDeq(largers);

	std::deque<int> smallers;
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largers[i])
			{
				smallers.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	std::deque<int> chain(largers.begin(), largers.end());
	chain.push_front(smallers[0]);

	std::vector<bool> inserted(smallers.size(), false);
	inserted[0] = true;

	size_t jIdx = 2;
	while (true)
	{
		size_t jVal = jacobsthal(jIdx);
		size_t prevJ = jacobsthal(jIdx - 1);
		if (prevJ >= smallers.size())
			break;
		size_t end = jVal;
		if (end > smallers.size())
			end = smallers.size();
		for (size_t k = end; k > prevJ; k--)
		{
			size_t idx = k - 1;
			if (idx < smallers.size() && !inserted[idx])
			{
				binaryInsertDeq(chain, smallers[idx], chain.size());
				inserted[idx] = true;
			}
		}
		jIdx++;
	}

	for (size_t i = 0; i < smallers.size(); i++)
	{
		if (!inserted[i])
			binaryInsertDeq(chain, smallers[i], chain.size());
	}

	if (hasStraggler)
		binaryInsertDeq(chain, straggler, chain.size());

	arr = chain;
}

// ========== Public interface ==========

void PmergeMe::printBefore() const
{
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::sort()
{
	printBefore();

	// Sort with vector
	std::vector<int> vecCopy(_vec);
	clock_t startVec = clock();
	mergeInsertSortVec(vecCopy);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	// Sort with deque
	std::deque<int> deqCopy(_deq);
	clock_t startDeq = clock();
	mergeInsertSortDeq(deqCopy);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	_vec = vecCopy;
	_deq = deqCopy;

	printAfter();
	std::cout << "Time to process a range of " << vecCopy.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deqCopy.size()
		<< " elements with std::deque : " << timeDeq << " us" << std::endl;
}
