#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int get_prior_number(vector<string> vec, vector<bool> visited) {
	int prior_i = -1;
	string prior = "";
	for(int i=0; i < vec.size(); i++) {
		int len_to_compare = prior.size();
		if(vec[i].size() < len_to_compare || !len_to_compare) len_to_compare = vec[i].size();
		bool isEqualInit = vec[i].substr(0, len_to_compare).compare(prior.substr(0, len_to_compare)) == 0;
		bool isSmaller = vec[i].size() < prior.size();

		if(
			(vec[i].substr(0, len_to_compare).compare(prior.substr(0, len_to_compare)) > 0 ||
			(isEqualInit && isSmaller)) &&
			!visited[i]
		) {
			prior = vec[i];
			prior_i = i;
		}
	}


	return prior_i;
}

// safe move: get number with max first number
string largest_number(vector<string> a) {
  std::stringstream ret;
	vector<bool> visited(a.size(), false);

  for (size_t i = 0; i < a.size(); i++) {
    int prior_i = get_prior_number(a, visited);
		ret << a[prior_i];
		visited[prior_i] = true;
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
