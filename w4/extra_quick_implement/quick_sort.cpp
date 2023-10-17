#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
	int pivot_index = left;			// fixed pivot on first element ;(
	int j = left;
	int pivot = arr[pivot_index];

	for(int i=left+1; i <= right; i++) {
		if(arr[i] <= pivot) {
			j++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[j], arr[pivot_index]);

	return j;
}

void quickSort(vector<int>& arr, int left, int right) {
	// TODO: Implement quick sort algorithm
	if(left >= right) return;
	int m = partition(arr, left, right);

	quickSort(arr, left, m - 1);
	quickSort(arr, m + 1, right);
}

int main() {
	vector<int> arr = {5, 2, 9, 1, 5, 6};
	quickSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
