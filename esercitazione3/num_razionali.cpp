#include <iostream>
#include <concepts>
#include "rational.hpp" 

int main(void)
{
rational<int> r1(6,7);
rational<int> r2(2,3);

std::cout << "r1= " << r1 << "\n";
std::cout << "r2= " << r2 << "\n";

rational<int> a = r1;
a += r2;
std::cout << "r1 += r2 -> " << a << "\n";

rational<int> b = r1 + r2;
std::cout << "r1 + r2 = " << b << "\n";

rational<int> c = r1;
c -= r2;
std::cout << "r1 -= r2 -> " << c << "\n";

rational<int> d = r1 - r2;
std::cout << "r1 - r2 = " << d << "\n";

rational<int> e = r1;
e *= r2;
std::cout << "r1 *= r2 -> " << e << "\n" ;

rational<int> f = r1 * r2;
std::cout << "r1 * r2 = " << f << "\n";

rational<int> g = r1;
g /= r2;
std::cout << "r1 /= r2 -> " << g << "\n";

rational<int> h = r1 / r2;
std::cout << "r1 / r2 = " << h << "\n";


return 0;
}