#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
int get_fibonacci_partial_sum_fast(long long from, long long to) {
	long long total = to;
	long long to_decrease = from - 1;
	long long pisano = get_pisano(10);

	int equivalent_fib_last_digit_total = get_fibonacci_last_digit_fast((total + 2) % pisano) - 1;
	int equivalent_fib_last_digit_decrease = get_fibonacci_last_digit_fast((to_decrease + 2) % pisano) - 1;

	int res = equivalent_fib_last_digit_total - equivalent_fib_last_digit_decrease;
	if(res < 0) {
		res += 10;
	};

	return res;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
