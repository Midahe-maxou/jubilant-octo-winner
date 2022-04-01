#include <iostream>
#include <cassert>
#include <numeric>
#include <string>
#include <array>

//#include "Matrice.hpp"

using string = std::string;

template<typename T>
class Foo {
public:
	Foo(const T& value = T()) {
		value_ = value;
	}
	friend Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs)
	{
		return Foo<int>(3);
	}
	friend std::ostream& operator<< (std::ostream& o, const Foo<T>& x)
	{
		o << x.getValue();
		return o;
	}

	T getValue() { return value_; }
private:
	T value_;
};

int main()
{
	/*std::array<int, 2> a1 = {1,2};
	std::array<int, 2> a2 = { 3,4 };
	std::array<int, 2> a3 = { 5,6 };
	std::array<std::array<int, 2>, 3> m = { a1, a2, a3};
	Matrice<3, 2> matrice{ m };

	std::cout << matrice << std::endl;*/
	
	Foo<string> f{ "lol" };
	Foo<string> g{ "mdr" };


	std::cout << f << "lol";
	

	return 0x0;
}