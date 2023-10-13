#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_max_index(vector<int> vec, vector<bool> blocked) {
	int res = -1;
	int comp = -INFINITY;
	for(int i=0; i < vec.size(); i++) {
		if(blocked[i]) continue;
		if(vec[i] > comp) {
			comp = vec[i];
			res = i;
		}
	}

	return res;
}


// safe choice: get put max payment avaible on max click placement avaliable
long long max_dot_product(vector<int> a, vector<int> b) {
	vector<bool> used_a(a.size(), false);
	vector<bool> used_b(b.size(), false);

	long long result = 0;
	for(size_t i=0; i < a.size(); i++) {
		int i_payment = get_max_index(a, used_a);
		int i_placement = get_max_index(b, used_b);

		result += ((long long) a[i_payment]) * b[i_placement];
		used_a[i_payment] = true;
		used_b[i_placement] = true;
	}

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
