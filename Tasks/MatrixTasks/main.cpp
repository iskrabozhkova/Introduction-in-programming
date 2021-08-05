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
//6.Local minimum

void findLocalMinimum (int** matrix, int rows, int cols) {
	int k = 0;
	for (int i = 1; i < rows-1; i++) {
		for (int j = 1; j < cols-1; j++) {
			if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i][j + 1] && matrix[i][j] < matrix[i + 1][j]) {
				std::cout << matrix[i][j];
			}
		}
	}
}

int** initializeMatrix(size_t n) {
	int** matrix = new int* [n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	return matrix;
}
//7.pattern A
int** printPartternA(int n) {
	int** result = initializeMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				result[i][j] = i;
			}
			else {
				result[i][j] = 0;
			}
		}
	}
	return result;
}
int** printPartternB(int n) {
	int** result = initializeMatrix(n);
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				result[i][j] = k++;
		}
	}
	return result;
}
int** printPartternC(int n) {
	int** result = initializeMatrix(n);
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[j][i] = k++;
		}
	}
	return result;
}
int** printPartternD(int n) {
	int** result = initializeMatrix(n);
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				result[i][j] = 1;
			}
			else if (i < j) {
				result[i][j] = j - i + 1;
			}
			else {
				result[i][j] = 0;
			}
		}
	}
	return result;
}
int* countArray(int arr1[], int n, int arr2[], int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr1[j] > arr1[j + 1]) {
				int temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}
	int* result = new int[n+m];
	int k = 0;
	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr2[i] > arr1[j]) {
				count++;
			}
		}
		result[k++] = count;
	}
	return result;
}

//Print all subarrays
void printSubArrays(int arr[], int n) {
	//starting point
	for (int i = 0; i < n; i++) {
		//ending point
		for (int j = i; j < n; j++) {
			//subarray between starting and ending point
			for (int k = i; k <= j; k++) {
					std::cout << arr[k] << " ";
			}
			std::cout << std::endl;
		}
	}
}
int main() {
	int arr1[] = { 3,1,3,1,7 };
	int arr2[] = { 4,8,2,0,6 };

	printSubArrays(arr1, 5);
	return 0;
}