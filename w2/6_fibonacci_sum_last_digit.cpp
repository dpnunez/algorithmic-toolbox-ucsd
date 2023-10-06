#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
	if(n <= 1) return n;
	int sum = 1;
	int current = 1;
	int previous = 0;
	for(int i=0; i < n - 1; ++i) {
			int tempPrevious = previous;
			previous = current;
			current = (tempPrevious + current) % 10;
			sum += current % 10;
		}

	return sum % 10;
}

void test_suit() {
	for(int i = 0; i <= 10; i++) {
		int fast = fibonacci_sum_fast(i);
		int naive = fibonacci_sum_naive(i);

		if(fast == naive) std::cout << "OK\n";
		else {
			std::cout << "ERROR (i: " << i << ";fast: " << fast << ";naive: " << naive << ")\n";
			break; 
		}
	}
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
		// test_suit();

		return 0;
}
