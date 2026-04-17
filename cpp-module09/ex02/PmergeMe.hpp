#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(PmergeMe const &rhs);

	// Jacobsthal number
	static size_t	jacobsthal(size_t n);

	// Ford-Johnson for vector
	void	mergeInsertSortVec(std::vector<int> &arr);
	void	binaryInsertVec(std::vector<int> &chain, int value, size_t maxPos);

	// Ford-Johnson for deque
	void	mergeInsertSortDeq(std::deque<int> &arr);
	void	binaryInsertDeq(std::deque<int> &chain, int value, size_t maxPos);

public:
	PmergeMe();
	~PmergeMe();

	void	parseArgs(int argc, char **argv);
	void	sort();
	void	printBefore() const;
	void	printAfter() const;
};

#endif
