#include <iostream>
#include <vector>

int get_change(int m) {
	int coins = 0;
	int amount = 0;

	while(amount < m) {
		if(amount + 10 <= m) amount+=10;
		else if(amount + 5 <= m) amount+=5;
		else if(amount + 1 <= m) amount+=1;
		coins++;
	}
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
