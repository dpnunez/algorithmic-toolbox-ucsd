#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;

void printTable(vector<int> &table) {
	cout << std::endl << "[ ";
	for(int i = 0; i < table.size(); i++) {
		cout << table[i] << ", ";
	}
	cout << " ]" << std::endl;
}

vector<int> optimal_sequence_dp(int n) {
	std::vector<int> sequence;
	std::vector<int> amount_operations_table;
	amount_operations_table.push_back(0);
	int number = 2;

	while(number <= n) {
		int t;
		int min;
		// plus 1
		t = number - 1;
		min = amount_operations_table[t - 1] + 1;

		// mult 2
		bool isDivisible = number % 2 == 0;
		if (isDivisible) {
			t = number / 2;
			min = std::min(min, amount_operations_table[t - 1] + 1);
		}
		// mult 3
		isDivisible = number % 3 == 0;
		if (isDivisible)
		{
			t = number / 3;
			min = std::min(min, amount_operations_table[t - 1] + 1);
		}

		amount_operations_table.push_back(min);
		number++;
	}

	int current_number = n;
	sequence.push_back(n);

	while(current_number > 1) {
		int aux_number = current_number - 1;
		int min_op = amount_operations_table[aux_number - 1];

		if(current_number % 2 == 0) {
			int n_aux = current_number / 2;
			if(amount_operations_table[n_aux - 1] < min_op) {
				min_op = amount_operations_table[n_aux - 1];
				aux_number = n_aux;
			}
		} 

		if(current_number % 3 == 0) {
			int n_aux = current_number / 3;
			if(amount_operations_table[n_aux - 1] < min_op) {
				min_op = amount_operations_table[n_aux - 1];
				aux_number = n_aux;
			}
		} 
		

		sequence.push_back(aux_number);
		current_number = aux_number;
	}
	int amount_operations = amount_operations_table[amount_operations_table.size() - 1]; 

	reverse(sequence.begin(), sequence.end());
	return sequence;
}


vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
