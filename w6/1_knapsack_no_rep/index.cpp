#include <iostream>
#include <vector>

using std::vector;

int optimal_weight_gredy(int W, const vector<int> &w) {
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

void print_matrix(const vector<vector<int>> &values) {
  for (int i = 0; i < values.size(); i++) {
    for (int j = 0; j < values[0].size(); j++) {
      std::cout << values[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int optimal_weight(int W, const vector<int> &w) {
  vector<vector<int>> values(w.size() + 1, vector<int>(W + 1));

  for (int r = 1; r < values.size(); r++) {
    for (int c = 1; c <= W; c++) {
      values[r][c] =
          values[r - 1][c]; // caso no qual w[c] ja esta contido na solucao
      if (w[r - 1] <= c) {
        int temp_val = values[r - 1][c - w[r - 1]] + w[r - 1];
        values[r][c] = std::max(values[r][c], temp_val);
      }
    }
  }

  // print_matrix(values);
  return values[values.size() - 1][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
