#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

// Work just with last digit of number (to avoid var overflow)
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


void stress_test() {
	for(int i = 0; i <= 40; i++) {
		int naive = get_fibonacci_last_digit_naive(i);
		int fast = get_fibonacci_last_digit_fast(i);
		std::cout << "i: " << i << std::endl;
		std::cout << "naive: " << naive << std::endl;
		std::cout << "fast: " << fast << std::endl;
		if(naive == fast) std::cout << "OK" << std::endl;
		else {
			std::cout << "Error: " << naive << " " << fast << std::endl;
			break;
		}
	}
}


int main() {
	int n;
	std::cin >> n;
	// stress_test();
	// int c = get_fibonacci_last_digit_naive(n);
	int c = get_fibonacci_last_digit_fast(n);
	std::cout << c << '\n';

	return 0;
}
