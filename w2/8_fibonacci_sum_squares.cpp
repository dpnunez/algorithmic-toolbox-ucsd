#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}


int fibonacci_sum_squares_ultra_fast(long long n) {
	bool isHoriozontal = true;
	int horizonal = 1;
	int vertical = 1;

	int current = 1;
	int previous = 0;

	for(int i = 0; i < n - 1; i++) {
		int temp_previous = previous;
		previous = current;
		current = (temp_previous + current) % 10;
		if (isHoriozontal) {
			horizonal = (horizonal + current) % 10;
		} else {
			vertical = (vertical + current) % 10;
		}

		isHoriozontal = !isHoriozontal;
	}

	return (vertical * horizonal) % 10;
}

int fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += (current * current) % 10;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_ultra_fast(n);
}
