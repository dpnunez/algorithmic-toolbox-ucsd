#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


int gcd_fast(int a, int b) {
	if(b == 0) {
		return a;
	};
	int aPrime = a % b;
	return gcd_fast(b, aPrime);
}



long long lcm_fast(long long a, long long b) {
	return (long long)(a * b) / gcd_fast(a, b);
}

void stress_test() {
	for(int i=0; i <= 10; i++) {
		for(int j=0; j <= 10; j++) {
			int naive = lcm_naive(i, j);
			int fast = lcm_fast(i, j);

			if(naive != fast) {
				std::cout << "error: " << i << j << std::endl;
				return;
			}
			std::cout << "ok" << std::endl;
		}
	}
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
