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

long long get_fibonacci_modulus(long long n, long long m) {
		long long amount = 10;
		if(m) amount = m;
		if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

		for(long long i=0; i < n - 1; ++i) {
			long long tempPrevious = previous;
			previous = current;
			current = (tempPrevious + current) % amount;
		}

    return current % amount;
}


long get_pisano_period(long m) {
    long prev = 0;
    long curr = 1;
    long res = 0;
 
    for(int i = 0; i < m * m; i++) {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
 
        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
	long long pisano_period = get_pisano_period(m);
	long long equivalent_i = n % pisano_period;
	return get_fibonacci_modulus(equivalent_i, m);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
		
		return 0;
}
