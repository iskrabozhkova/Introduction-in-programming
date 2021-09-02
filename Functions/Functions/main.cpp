#include <iostream>

int* decToBin(int num) {
	int* binary = new int[33];
	int* rev = new int[33];
	int i = 0;
	int length = 0;

	while (num != 0) {
		binary[i] = num % 2;
		num /= 2;
		i++;
		length++;
	}
	for (int i = 0; i < length; i++) {
		rev[i] = binary[length - i - 1];
	}
	return rev;
}
int binToDec(int num) {
	int base = 1;
	int dec = 0;
	while (num != 0) {
		dec = dec + (num % 10) * base;
		num /= 10;
		base = base * 2;
	}
	return dec;
}
int strlen(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
bool isFound(char* str, char c) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == c) {
			return true;
		}
	}
	return false;
}
char* findShortest(char* main, char* sub) {
	int len_main = strlen(main);
	int len_sub = strlen(sub);
	int counter = 0;
	int min = 123456;

	for (int i = 0; i < len_main; i++) {
		//counter = 0;
		if (isFound(sub, main[i])) {
			counter++;
		}
		else {
			if (counter != 0 && min > counter) {
				min = counter;
			}
			counter = 0;
		}
	}
	//we know that min is 3
	int start_index = 0;
	counter = 0;
	for (int i = 0; i < len_main; i++) {
		if (isFound(sub, main[i])) {
			counter++;
		}
		else {
			if (counter != 0 && min == counter) {
				start_index = i - min;
			}
			counter = 0;
		}
	}
	char* res = new char[min + 1];
	for (int i = 0; i < min; i++) {
		res[i] = main[start_index];
		start_index++;
	}
	res[min] = '\0';
	return res;
}
int length(int num) {
	int length = 0;
	while (num != 0) {
		num /= 10;
		length++;
	}
	return length;
}
bool isThereEqual(int num) {
	int len = length(num);
	int* arr = new int[len + 1];
	for (int i = len - 1; i >= 0; i--) {
		arr[i] = num % 10;
	}
	for (int i = 1; i < len; i++) {
		if (arr[0] == arr[i]) {
			return true;
		}
	}
	return false;
}
int* rotate(int arr[], int n, int M) {
	int* result = new int[n + 1];
	for (int i = 0; i < n - M; i++) {
		result[i + M] = arr[i];
	}
	for (int i = 0; i < n - M - 1; i++) {
		int pos = n - M;
		result[i] = arr[pos + i];

	}
	return result;
}
void minElement(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		int min = matrix[i][0];
		for (int j = 0; j < m; j++) {
			if (min > matrix[i][j]) {
				min = matrix[i][j];
			}
		}
		std::cout << min;
	}
}
void countNegative(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] < 0) {
				count++;
			}
		}
		std::cout << count << " ";
	}
}
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
bool isSymetric(int** matrix, int n) {
	int** transp = transpose(matrix, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != transp[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool isTriangle(int** matrix, int n) {
	bool flag = true;
	bool other_flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && matrix[i][j] != 0) {
				flag = false;
			}
			if (i > j && matrix[i][j] != 0) {
				other_flag = false;
			}
		}
	}
	if (flag == true || other_flag == true) {
		return 1;
	}
	else {
		return 0;
	}
}
int checkTimeStr(char str[]) {
	//12:42:13
	int len = strlen(str);
	if (len != 8) {
		return -1;
	}
	int hours = 0;
	for (int i = 0; i < 2; i++) {
		hours = (hours * 10) + (str[i] - '0');
	}
	int min = 0;
	for (int i = 3; i < 5; i++) {
		min = (min * 10) + (str[i] - '0');
	}
	int sec = 0;
	for (int i = 6; i < 8; i++) {
		sec = (sec * 10) + (str[i] - '0');
	}
	if (min >= 0 && min <= 24 && sec >= 0 && sec <= 60 && hours >= 0 && hours <= 24 && str[2] == ':' && str[5] == ':') {
		return true;
	}
	else {
		return false;
	}
}
int findNumberFibonacii(int toSearch) {
	int num = 0;
	int num2 = 1;
	int temp = 0;
	int counter = 2;
	while (temp != toSearch) {
		temp = num + num2;
		num = num2;
		num2 = temp;
		counter++;
	}
	return counter;
}
int sumFibonaciiNumbers(int n, int m) {
	int sum = n;
	//0 1 1 2 3 5 8
	int start = 0;
	int next = 1;
	int temp = 0;

	while (temp != n) {
		temp = start + next;
		start = next;
		next = temp;
		if (temp == n) {
			while (temp != m) {
				temp = start + next;
				start = next;
				next = temp;
				sum += temp;
			}
			break;
		}
	}
	return sum;
}
char* deleteDublicate(char* str) {
	int len = strlen(str);
	char* res = new char[len + 1];

	int k = 0;
	int i = 1;
	while (i <= len) {
		if (str[i] != str[i - 1]) {
			res[k] = str[i - 1];
			k++;
			i++;
		}
		else {
			i++;
		}
	}
	res[k] = '\0';
	return res;
}
int** findMatrixSum(int** first, int** second, int n) {
	int** result = new int* [n];
	for (int i = 0; i < n; i++) {
		result[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = first[i][j] + second[i][j];
		}
	}
	return result;
}
int** multiplyMatrixes(int** A, int n1, int m1, int** B, int n2, int m2) {
	if (n1 != m2) {
		return nullptr;
	}
	int** matrix = new int* [n1];
	for (int i = 0; i < n1; i++) {
		matrix[i] = new int[m2];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < m1; k++) {
				matrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return matrix;
}
int* find_cuadroncacii(int arr[], int n) {
	int sum = 0;
	int* res = new int[n];
	int k = 1;

	res[0] = arr[0];

	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			sum += arr[j];
		}
		if (sum < arr[i]) {
			res[k] = arr[i];
			k++;
		}
		sum = 0;
	}
	return res;
}