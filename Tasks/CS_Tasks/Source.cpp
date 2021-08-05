#include <iostream>

unsigned progression(int arr[], unsigned n) {
	int count = 1;
	int maxCount = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[i + 1]) {
			count++;
		}
		else {
			if (count > maxCount) {
				maxCount = count;
			}
			count = 1;
		}
	}
	return maxCount;
}

//every time you find bigger number -> increase count
int visibleIndians(int arr[], int n) {
	int count =0;
	int maxHeight = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxHeight) {
			maxHeight = arr[i];
			count++;
		}
	}
	return count;
}
bool isBalanced(int arr[], int n) 
{
	if (n <= 0) {
		return 0;
	}
	if (n % 2 == 0) {
		int middle = n / 2;
		int leftSum = 0;
		int rightSum = 0;
		for (int i = 0; i < middle; i++) {
			leftSum += arr[i];
		}
		for (int i = middle; i < n; i++) {
			rightSum += arr[i];
		}
		if (leftSum == rightSum) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		int middle = n / 2;
		int leftSum = 0;
		int rightSum = 0;
		for (int i = 0; i < middle; i++) {
			leftSum += arr[i];
		}
		for (int i = middle + 1; i < n; i++) {
			rightSum += arr[i];
		}
		if (leftSum == rightSum) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
int strlen(char str[]) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
bool isLower(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		return true;
	}
	return false;
}
bool isUpper(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return true;
	}
	return false;
}
int maxOccurs(char str[]) {
	char alphabet[26];
	int len = strlen(str);

	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		if (isLower(str[i])) {
			alphabet[(int)str[i] - 97]++;
		}
		if (isUpper(str[i])) {
			alphabet[(int)str[i] - 65]++;
		}

	}
	int max = (int)alphabet[0];
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
		}
	}
	return max;
}

int main() {
	char str[] = { "pOolo" };
	std::cout << maxOccurs(str);


	return 0;
}