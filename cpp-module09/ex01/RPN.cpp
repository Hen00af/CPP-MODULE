#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &copy) : _stack(copy._stack) {}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return *this;
}

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPN::applyOp(double a, double b, char op) const
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return a / b;
	}
	return 0;
}

double RPN::evaluate(std::string const &expression)
{
	while (!_stack.empty())
		_stack.pop();

	for (std::string::size_type i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (c == ' ')
			continue;
		if (c >= '0' && c <= '9')
		{
			_stack.push(c - '0');
		}
		else if (isOperator(c))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			double b = _stack.top(); _stack.pop();
			double a = _stack.top(); _stack.pop();
			_stack.push(applyOp(a, b, c));
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}
