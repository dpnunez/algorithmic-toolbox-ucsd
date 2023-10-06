#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

		int index1 = -1;
		int index2 = -1;
		int highest = -1;
		int current = 0;

		for(int i = 0; i < n; i++) {
			current = numbers[i];
			if(current > highest) {
				highest = current;
				index1 = i;
			}
		}

		highest = -1;
		for(int i = 0; i < n; i++) {
			current = numbers[i];
			if(current > highest && i != index1) {
				highest = current;
				index2 = i;
			}
		}

    return ((long long)numbers[index1]) * numbers[index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}


// Stress test
// int main() {
// 	while(true) {
// 		int n = rand() % 10 + 2;
// 		std::cout << n << "\n";
// 		std::vector<int> a;
// 		for(int i = 0; i < n; i++) {
// 			a.push_back(rand() % 100000);
// 		}

// 		for(int i = 0; i < n; i++) {
// 			std::cout << a[i] << ' ';
// 		}

// 		long long res1 = MaxPairwiseProduct(a);
// 		long long res2 = MaxPairwiseProductFast(a);
// 		if (res1 != res2) {
// 			std::cout << "Wrong answer: " << res1 << " " << res2 << "\n";
// 			break;
// 		}
// 		else {
// 			std::cout << "OK\n";
// 		}
// 	}
// }
