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

long long get_pisano(int m) {
	int i=0;
	long long prev = 0;
	long long current = 1;

	while(true) {
		long long temp = current;
		current = (prev + current) % m;
		prev = temp;
		if(prev == 0 && current == 1) {
			return i + 1;
		}
		i++;
	}
}

int get_fibonacci_last_digit_fast(int n) {
		if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

		for(int i=0; i < n - 1; ++i) {
			int tempPrevious = previous;
			previous = current;
			current = (tempPrevious + current) % 10;
		}

    return current % 10;
}

// Fsum = F(n + 2) - 1
int fibonacci_sum_fast(long long n) {
	long long pisano = get_pisano(10);
	int equivalent_fib_last_digit = get_fibonacci_last_digit_fast((n + 2) % pisano) - 1;

	if(equivalent_fib_last_digit < 0) return 9;

	return equivalent_fib_last_digit;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
