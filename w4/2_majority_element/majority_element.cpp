#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element_naive(vector<int> &a) {
	for(int i=0; i < a.size(); i++) {
		int count = 0;
		for(int j=0; j < a.size(); j++) {
			if(a[i] == a[j]) count++;
		}
		if(count > a.size()/2) return 1;
	}

	return 0;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return 0;
  if (left + 1 == right) return a[left];
  
	int mid = left + (right - left)/2;

	int lower = get_majority_element(a, left, mid);
	int higher = get_majority_element(a, mid, right);


	if (lower == 0 && higher == 0) return 0;
	if (lower == higher) return lower;
		// count higher
		int to_count_1 = std::max(lower, higher);
		int to_count_2 = std::min(lower, higher);
		int count_1 = 0;
		int count_2 = 0;
		for(int i=left; i < right; i++) {
			if (a[i] == to_count_1) {
				count_1++;
			} else if (a[i] == to_count_2) {
				count_2++;
			}
		}

		if (count_1 > ((double)right - left)/2) {
			return to_count_1;
		} else if (count_2 > ((double)right - left)/2) {
			return to_count_2;
		} else {
			return 0;
		}
}

void stress_test() {
	while(true) {
		int size = rand() % 10;
		vector<int> a(size);
		for(int i=0; i < size; i++) {
			a[i] = (rand() % 10) + 1;
		}

		// print vector
		for(int i=0; i < size; i++) {
			std::cout << a[i] << " ";
		}

		if (get_majority_element_naive(a) != (get_majority_element(a, 0, a.size()) != 0)) {
			std::cout << "Wrong answer: " << get_majority_element_naive(a) << " " << (get_majority_element(a, 0, a.size()) != 0) << "\n";
			break;
		} else {
			std::cout << "OK\n";
		}
	}
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
	// std::cout << (get_majority_element_naive(a)) << '\n';
  std::cout << (get_majority_element(a, 0, a.size()) != 0) << '\n';
	// stress_test();
}
