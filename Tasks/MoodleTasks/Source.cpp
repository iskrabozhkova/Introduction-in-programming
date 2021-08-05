#include <iostream>

//1
int* mergeSorted(int arr1[], int len1, int arr2[], int len2) {
	int* result = new int[len1 + len2 + 1];

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < len1 || j < len2) {
		if (i == len1 || j == len2) {
			if (i == len1) {
				result[k] = arr2[j];
				k++;
				j++;
			}
			if (j == len2) {
				result[k] = arr1[i];
				k++;
				i++;
			}
		}
		else {
			if (arr1[i] <= arr2[j]) {
				result[k++] = arr1[i];
				i++;
			}
			else {
				result[k++] = arr2[j];
				j++;
			}
		}
	}
	return result;
}
//4.
int sumAboveMainDiagonal(int** matrix, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}
//5. 
int** transpose(int** matrix, int n) {
	int** transpose = new int* [n];
	for (int i = 0; i < n; i++) {
		transpose[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			transpose[i][j] = matrix[j][i];
		}
	}
	return transpose;
}
int** init(int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}
void printMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int** matrix = init(3);
	printMatrix(matrix, 3);
	int** transposed = transpose(matrix, 3);
	printMatrix(transposed, 3);
	return 0;
}