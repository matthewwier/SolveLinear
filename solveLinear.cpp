#include <iostream>
using namespace std;
extern const double zero = 0;

template <class typCiala, typCiala zero > typCiala solveLinear(typCiala a, typCiala b)
{
	if (a == b && a == zero)
	{
		return 0;
	}
	else if (a == 0 && b != zero)
	{
		throw std::domain_error(std::string("No solutions for linear equation of type " + std::string(typeid(typCiala).name())));
	}
	else
	{
		typCiala x0 = -b / a;
		return x0;
	}
}
template <class typCiala, const typCiala& zero> typCiala solveLinear(typCiala *a, typCiala *b)
{
	if (*a == *b && *a == zero)
	{
		return 0;
	}
	else if (*a == 0 && *b != zero)
	{
		throw std::domain_error(std::string("No solutions for linear equation of type " + std::string(typeid(typCiala).name())));
	}
	else
	{
		typCiala x0 = -(*b / *a);
		return x0;
	}
}
template <class typCiala, const typCiala& zero> typCiala solveLinear(typCiala a, typCiala b)
{
	if (a == b && a == zero)
	{
		return 0;
	}
	else if (a == 0 && b != zero)
	{
		throw std::domain_error(std::string("No solutions for linear equation of type " + std::string(typeid(typCiala).name())));
	}
	else
	{
		typCiala x0 = -(b / a);
		return x0;
	}
}
template <class typCiala> typCiala solveLinear(typCiala *a, typCiala *b)
{
	typCiala zero = 0;
	if (*a == *b && *a == zero)
	{
		return 0;
	}
	else if (*a == 0 && *b != zero)
	{
		throw std::domain_error(std::string("No solutions for linear equation of type " + std::string(typeid(typCiala).name())));
	}
	else
	{
		typCiala x0 = -(*b / *a);
		return x0;
	}
}
template <class typCiala> typCiala solveLinear(typCiala a, typCiala b)
{
	typCiala zero = 0;
	if (a == b && a == zero)
	{
		return 0;
	}
	else if (a == 0 && b != zero)
	{
		throw std::domain_error(std::string("No solutions for linear equation of type " + std::string(typeid(typCiala).name())));
	}
	else
	{
		typCiala x0 = -(b / a);
		return x0;
	}
}

int main()
{
	try
	{
		double a = 5, b = 0, c = 2;
		std::cout << solveLinear<double, zero>(&a, &c) << std::endl;
		std::cout << solveLinear<double>(&a, &c) << std::endl;
		std::cout << solveLinear<double, zero>(a, c) << std::endl;
		std::cout << solveLinear(a, c) << std::endl;

		std::cout << solveLinear<int>(7, 5) << std::endl;
		std::cout << solveLinear<unsigned>(9, 3) << std::endl;

		std::cout << solveLinear<double, zero>(&b, &c) << std::endl;
		std::cout << solveLinear<double>(&b, &c) << std::endl;
		std::cout << solveLinear<double, zero>(b, c) << std::endl;
		std::cout << solveLinear(b, c) << std::endl;
	}
	catch (const std::domain_error &e)
	{
		cout << e.what() << endl;
	}
}
