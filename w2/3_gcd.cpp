#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
	if(b == 0) {
		return a;
	};
	int aPrime = a % b;
	return gcd_fast(b, aPrime);
}

void stress_test() {
	while(true) {
		int randomA = rand() % 10;
		int randomB = rand() % 10;

		std::cout << randomA << " " << randomB << std::endl;
		int res_fast = gcd_fast(randomA, randomB);
		int res_naive = gcd_naive(randomA, randomB);

		if(res_fast != res_naive) {
			std::cout << "Wrong answer: " << res_fast << " " << res_naive << std::endl;
			break;
		} else {
			std::cout << "OK" << std::endl;
		}
	}
}

int main() {
  int a, b;
	// stress_test();
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
