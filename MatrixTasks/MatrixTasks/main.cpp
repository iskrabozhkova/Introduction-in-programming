#include <iostream>

int** inputMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i]= new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}
void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void releaseMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

//1.sum of elements over the main diagonal without it
//if we want to add the diagonal --> if (i <= j)
int findSumOverMainDiagonal(int** matrix, int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i < j) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

//2.sum of elements under the main diagonal without it
//if we want to add the diagonal --> if (i >= j)
int findSumUnderMainDiagonal(int** matrix, int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i > j) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}
//3.sum of elements from main diagonal
int sumFromMainDiagonal(int** matrix, int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += matrix[i][i];
	}
	return sum;
}
//4.sum of elements from secondary diagonal
int sumFromSecondaryDiagonal(int** matrix, int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += matrix[i][rows - i - 1];
	}
	return sum;
}
//5.number of rows containing at least 1 negative number
int rowsWithNegative(int** matrix, int rows, int cols) {
	int count = 0;

	for (int i = 0; i < rows; i++) {
		bool flag = false;
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] < 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			count++;
		}
	}
	return count;
}


int main() {
	int** matrix = inputMatrix(3, 3);
	printMatrix(matrix, 3,3);
	
	return 0;
}