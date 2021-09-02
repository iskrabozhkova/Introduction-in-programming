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
int strlen(char str[]) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
void revert(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		bool isLower = str[i] >= 'a' && str[i] <= 'z';
		bool isUpper = str[i] >= 'A' && str[i] <= 'Z';
		str[i] += isUpper * 32 + isLower * (-32) ;
	}
}
int digitPos(long num, int k) {
	int len = 0;
	long temp = num;
	while (temp != 0) {
		temp /= 10;
		len++;
	}
	if (len <= 0) {
		return -1;
	}
	if (k <= 0 || k > len) {
		return -1;
	}
	int* arr = new int[len + 1];

	for (int i = len - 1; i >= 0; i--) {
		int lastDigit = num % 10;
		arr[i] = lastDigit;
		num /= 10;
	}
	return arr[k - 1];
}
bool doExist(char symbols[], char word[]) {
	int symbols_len = strlen(symbols);
	int word_len = strlen(word);

	int i = 0;
	int j = 0;
	while (i < symbols_len && j < word_len) {
		if (symbols[i] == word[j]) {
			
			i++;
			j++;
			if (j == word_len) {
				return true;
			}
		}
		else {
			i++;
			j = 0;
		}
	}
	return false;
}
//Recursion tasks
//1.
int func(int n) {
	if (n == 1) {
		return 1;
	}
	if (n % 3 == 1) {
		return n * func(n - 3);
	}
	return func(n - 1);
}
//2.
int countOccur(int n, int k) {
	if (n < 10) {
		return k;
	}
	return (n / 10, k) + (n % 10 == k);
}
//3
bool isPowOfTwo(int n) {
	if (n == 2) {
		return true;
	}
	if (n % 2 == 1) {
		return false;
	}
	return isPowOfTwo(n / 2);
}
int main() {
	std::cout << isPowOfTwo(10);
		
		return 0;
}