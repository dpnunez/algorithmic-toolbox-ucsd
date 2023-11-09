#include <iostream>
#include <string>
#include <vector> 

using std::vector;
using std::string;

void printMatrix(vector<vector<int>> matrix, int rows, int columns) {
  std::cout << "Matrix: " << std::endl;
  for(int i=0; i<rows; i++) {
    for(int j=0; j<columns; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void fillFirstLineAndColumns(vector<vector<int>> &matrix, int rows, int columns) {
  for(int i=0; i<rows; i++) {
    matrix[i][0] = i;
  }
  for(int j=0; j<columns; j++) {
    matrix[0][j] = j;
  }
}

int edit_distance(const string &str1, const string &str2) {
	int size1 = str1.size() + 1;
	int size2 = str2.size() + 1;

  vector<vector<int>> matrix_distance(size1 , vector<int> (size2));  	
  fillFirstLineAndColumns(matrix_distance, size1, size2);
  
  for(int i=1; i<size1; i++) {
    for(int j=1; j<size2; j++) {
      // get min between
      int indel = std::min(matrix_distance[i-1][j]+1, matrix_distance[i][j-1]+1);
      int match = matrix_distance[i-1][j-1];
      int missmatch = match + 1;


      int bestChoice;
      if (str1[i - 1] == str2[j - 1]) {
        // use match
        bestChoice = std::min(indel, match);
      } else {
        bestChoice = std::min(indel, missmatch);
      }
      matrix_distance[i][j] = bestChoice;
    }
  }

	// printMatrix(matrix_distance, size1, size2);
  return matrix_distance[size1-1][size2-1]; 
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
