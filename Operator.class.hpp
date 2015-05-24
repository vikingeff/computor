#ifndef OPERATOR_CLASS_HPP
# define OPERATOR_CLASS_HPP

# include <iostream>
# include <string>

class Operator
{

public:
	Operator();
	Operator(Operator const & ref);
	~Operator();

	Operator &				operator=(Operator const & source);
	static int				getNbOperator();

private:
	static int				_nbOperator;

};

#endif
