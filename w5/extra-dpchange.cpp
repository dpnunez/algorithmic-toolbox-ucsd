#include <iostream>
#include <vector>

using std::vector;

void printChargeTable(vector<int> &coins) {
	std::cout << "charge table dp: " << std::endl;
	for (size_t i = 0; i < coins.size(); i++) {
		std::cout << coins[i] << std::endl;
	}
	
}

int DPCharge(int amount, vector<int> &coins) {
	vector<int> chargeTable(amount + 1);

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

	printChargeTable(chargeTable);
	return 0;
}


int main(){
	int amount;
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(8);
	coins.push_back(20);

	std::cin >> amount;
	DPCharge(amount, coins);
	
	return 0;
}