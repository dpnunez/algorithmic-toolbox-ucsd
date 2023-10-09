#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::cout;

int pick_best_product(vector<int> weights, vector<int> values) {
	int best_i = 0;
	double best_relation = 0;
	for(int i=0; i < weights.size(); i++) {
		if(weights[i] == 0) continue;
		double relation = (double)values[i] / weights[i];
		if(relation > best_relation) {
			best_relation = relation;
			best_i = i;
		}
	}

	return best_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
	int w = capacity;


	// loop in weights or values
	// 	end condition (w == 0)
	//	pick element with best price unit relation (function)
	// 	calc price per unit
	//	calc amount to be picked
	// 	value += a*price_per_unit
	//	remove item amount from weight vetor
	// 	w -= a;


	for(int i=0; i < weights.size(); i++) {
		if(w == 0) break;
		int best_i = pick_best_product(weights, values);
		double relation = (double)values[best_i] / weights[best_i];
		double amount = min(w, weights[best_i]);
		value += amount*relation;
		w -= amount;
		weights[best_i] = 0;
	}

  return value;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;

  return 0;
}
