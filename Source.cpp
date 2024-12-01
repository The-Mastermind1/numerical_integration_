#include"Header.h"

int main() {
	double a;
	double b;
	std::cout << "insert a,b for interval:[a,b]\n";
	std::cout << "a:";
	std::cin >> a;

	std::cout << "b:";
	std::cin >> b;

	double h = 0.1;
	double xi = 0.0;
	assert(a < b);
	size_t iterations = static_cast<size_t>((b - a) / h);
	double sum = 0;
	for (size_t i = 0; i < iterations - 1; i++) {
		double itrap = (f(xi) + f(xi + h)) * h / 2;
		sum += itrap;
		xi += h;

	}
	double ireal = 0;//ireal for f(x)=sin(4*pi*x) in [0,2] is zero
	std::cout << "Itrap: " << std::setprecision(8) << sum << '\n';
	std::cout <<"ERROR: " << std::setprecision(8) << std::abs(ireal - sum) << '\n';
	std::cout << "\n\n\n";
	h = 0.1;
	xi = 0.0;
	//iterations = static_cast<size_t>((b - a) / h); (Again)
	sum = 0;
	for (size_t i = 0; i < iterations - 1; i++) {
		double isimp = (f(xi) + 4 * f((xi + xi + h) / 2) + f(xi + h))*(h/6);
		sum += isimp;
		xi += h;
	}

	std::cout << "ISIMP: " << std::setprecision(8) << sum << '\n';
	std::cout << "ERROR: " << std::setprecision(8) << std::abs(ireal - sum) << '\n';
}
