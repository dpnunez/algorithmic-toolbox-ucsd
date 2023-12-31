#include <iostream>
#include <vector>

using std::vector;

int merge(vector<int> &arr, vector<int> &temp, int left, size_t mid, int right) {
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid;
    k = left;

    while ((i < mid) && (j < right)) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
						i++;
        }
        else {
            temp[k] = arr[j];
						j++;
            inv_count += (mid - i);
        }
				k++;
    }
 
    while (i < mid)
        temp[k++] = arr[i++];
 
    while (j < right)
        temp[k++] = arr[j++];

    for (i = left; i < right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right - left <= 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;

  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);

	number_of_inversions += merge(a, b, left, ave, right);
	
	return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
	vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size());

	return 0;
}
