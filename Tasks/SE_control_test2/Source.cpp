#include <iostream>

int** init(int n) {
	int** matrix = new int*[n];
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
void printMat(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int countRows(int** matrix, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == matrix[i][j+1] - 1 == matrix[i][j+2] - 2) {
				count++;
			}
		}
	}
	return count;
}
unsigned long countSums(long arr1[], long n1, long arr2[], long n2, long arr3[], long n3) {
	unsigned long count = 0;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			for (int k = 0; k < n3; k++) {
				if (arr1[i] == arr2[j] + arr3[k] || arr2[j] == arr1[i] + arr3[k] || arr3[k] == arr2[j] + arr1[i]) {
					count++;
				}
			}
		}
	}
	return count;
}
int main() {
	long arr1[] = { 1,5,3 };
	long arr2[] = { 2,4 };
	long arr3[] = { 6,3,0 };

	std::cout << countSums(arr1, 3, arr2, 2, arr3, 3);

	return 0;
}