#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
private:
	std::stack<double>	_stack;

	RPN(RPN const &copy);
	RPN &operator=(RPN const &rhs);

	bool	isOperator(char c) const;
	double	applyOp(double a, double b, char op) const;

public:
	RPN();
	~RPN();

	double	evaluate(std::string const &expression);
};

#endif
