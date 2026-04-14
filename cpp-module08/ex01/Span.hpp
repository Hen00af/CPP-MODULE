#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

	Span();

public:
	Span(unsigned int n);
	Span(Span const &copy);
	~Span();
	Span &operator=(Span const &rhs);

	void			addNumber(int number);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end)
	{
		unsigned int dist = 0;
		for (InputIterator tmp = begin; tmp != end; ++tmp)
			dist++;
		if (_numbers.size() + dist > _maxSize)
			throw std::overflow_error("Span is full: cannot add range");
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif
