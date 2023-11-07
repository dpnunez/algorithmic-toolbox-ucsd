#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int get_change(int m, vector<int> &coins) {
	vector<int> chargeTable(m + 1);

	if(m < coins[0]) return 1;

	for (size_t i = 0; i < chargeTable.size(); i++)	{
		if (i == 0) chargeTable[i] = 0;
		else {
			int min = INFINITY;
			for (size_t j = 0; j < coins.size(); j++) {
				int calc = i - coins[j];
				if (calc < 0) continue;
				if (chargeTable[calc] + 1 < min)
					min = chargeTable[calc] + 1;
			}

			chargeTable[i] = min;
		}
	}

	return chargeTable[chargeTable.size() -1];	
}

int main() {
  int m;
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(3);
	coins.push_back(4);

  std::cin >> m;
  std::cout << get_change(m, coins) << '\n';
}
