#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
	int total_given = 0;
	int i = 1;

	while(total_given < n) {
		total_given+=i;
		summands.push_back(i);
		i++;
	}

	if(total_given > n) {
		int last = summands[summands.size() - 1];
		total_given -= last;
		summands.pop_back();

		last = summands[summands.size() - 1];
		total_given -= last;
		summands.pop_back();
		

		summands.push_back(n - total_given);
	}

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
