
#include <cstdlib>
#include <ctime>

class Random {

public:

	Random() {
		std::srand(std::time(0));
	}

	Random(int seed) {
		std::srand(seed);
	}

	int next_int(int n) {
		return int(next_double() * n);
	}

	double next_double() {
		double num= double(std::rand()) / RAND_MAX;
		return num;
	}

};
