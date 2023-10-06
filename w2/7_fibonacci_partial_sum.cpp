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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
	int current = 1;
	int previous = 0;

	for(int i=0; i < from; i++) {
		int temp_previous = previous;
		previous = current;
		current = (temp_previous + current) % 10;
	}

	if (from == to) return previous % 10;

	int sum = current + previous;

	std::cout << "base: " << sum << "\n";
	std::cout << "current: " << current << "\n";
	std::cout << "previous: " << previous << "\n";

	for(int i = 0; i < to - from - 1; i++) {
		int temp_previous = previous;
		previous = current;
		current = (temp_previous + current) % 10;
		std::cout << "current: " << current << "\n";
		sum += current % 10;
	}

	std::cout << "\n";

	

	return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
