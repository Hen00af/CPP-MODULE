#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(Span const &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span::~Span() {}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(maxVal - minVal);
}
