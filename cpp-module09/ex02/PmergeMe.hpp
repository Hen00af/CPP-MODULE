#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(PmergeMe const &rhs);

	struct Element
	{
		int value;
		std::size_t id;
		Element(int v, std::size_t i) : value(v), id(i) {}
	};

	void mergeInsertSortVec(std::vector<int> &arr, std::size_t &step);
	void sortElementsVec(std::vector<Element> &arr, std::size_t &step);
	void binaryInsertVec(std::vector<Element> &chain, const Element &element,
		std::size_t maxPos, std::size_t &step);

	void mergeInsertSortDeq(std::deque<int> &arr, std::size_t &step);
	void sortElementsDeq(std::deque<Element> &arr, std::size_t &step);
	void binaryInsertDeq(std::deque<Element> &chain, const Element &element,
		std::size_t maxPos, std::size_t &step);


public:
	PmergeMe();
	~PmergeMe();

	void	parseArgs(int argc, char **argv);
	void	sort();
	void	printBefore() const;
	void	printAfter() const;
};

#endif
