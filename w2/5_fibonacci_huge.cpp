#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_fib_remain(int n, int m) {
		if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

		for(int i=0; i < n - 1; ++i) {
			int tempPrevious = previous;
			previous = current;
			current = (tempPrevious + current) % m;
		}

    return current % m;
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

long long get_fibonacci_huge_fast(long long n, long long m) {
	long long pisano = get_pisano(m);
	long long equivalent_fib = n % pisano;
	return get_fib_remain(equivalent_fib, m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

		return 0;
}
