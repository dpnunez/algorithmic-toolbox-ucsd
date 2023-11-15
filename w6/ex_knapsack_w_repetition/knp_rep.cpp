#include <iostream>
#include <vector>

using std::vector;

int knap(int n, int capacity, vector<int> &v, vector<int> &w) {
  vector<int> chunk_values(capacity + 1);
  chunk_values[0] = 0;

  for (int i = 1; i <= capacity; i++) {
    int value = 0;
    for (int j = 0; j < n; j++) {
      if (w[j] <= i) {
        int value_temp = chunk_values[i - w[j]] + v[j];
        if (value_temp > value) {
          value = value_temp;
        }
      }
    }
    chunk_values[i] = value;
  }

  return chunk_values[capacity];
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

  std::cout << knap(n, capacity, values, weights);
  return 0;
}
