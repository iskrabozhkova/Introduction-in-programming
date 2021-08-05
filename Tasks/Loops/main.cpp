#include <iostream>

double meanDigits(long long number) {
	long long temp = number;
	double sum = 0;
	int counter = 0;
	while (temp != 0) {
		sum += temp % 10;
		counter++;
		temp /= 10;
	}
	return sum / counter;
}
//123456 --> 3 654321
int digitPos(long long num, int k) {
	long long temp = num;
	int counter = 0;
	long long reversed = 0;
	int len = 0;
	while (temp != 0) {
		reversed = reversed * 10 + temp % 10;
		temp /= 10;
		len++;
	}
	if (k > len || k <= 0) {
		return -1;
	}
	while (reversed != 0) {
		reversed /= 10;
		counter++;
		if (counter == k-1) {
			break;
		}
	}
	return reversed % 10;
}

bool isPrime(int number) {

	bool isPrime = true;
	if (number == 1 || number == 0) {
		isPrime = false;
	}
	if (number == 2) {
		isPrime = true;
	}
	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime) {
		return 1;
	}
	else {
		return 0;
	}
}

int findNumberContain(int arr1[], int len1, int arr2[], int len2) {
	int count = 0;
	if (len2 < len1) return count;
	else {
		for (size_t i = 0; i < len2 - len1 + 1; i++) {
			if (arr2[i] == arr1[0]) {
				for (size_t j = 1; j < len1; j++) {
					if (arr2[i + j] == arr1[j]) {
						if (j == len1 - 1) {
							count++;
							i += j;
							break;
						}
					}
					else break;
				}
			}
		}
	}
	return count;
}

int longestTrain(int arr[], int n) {
	int count = 1;
	int maxCount = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i+1]) {
			count++;
		}
		else {
			if (count > maxCount) {
				maxCount = count;
			}
			count = 1;
		}
	}
	int index = 0;
	 count = 1;
	for (int i = 0; i < n; i++) {
		if (count == 1) {
			index = i;
		}
		if (arr[i] == arr[i + 1]) {
			count++;
		}
		else {
			if (count == maxCount) {
				break;
			}
			count = 1;
		}
		
	}
	return index;
}
bool isSymetric(int arr[], int n) {
	if (n <= 0) {
		return -1;
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[n - i - 1]) {
			flag = true;
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		return 1;
	}
	else {
		return 0;
	}
}
void printLongest(int arr[], int n) {
	int count = 0;
	int maxCount = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[i + 1]) {
			count++;
		}
		else {
			if (count > maxCount) {
				maxCount = count;
			}
			count = 0;
		}
	}
	count = 0;
	int begin = 0;
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			begin = i;
		}
		if (arr[i] < arr[i + 1]) {
			count++;
		}
		else {
			if (count == maxCount) {
				break;
			}
			count = 0;
		}
	}
	int end = maxCount + begin;
	for (int i = begin; i <= end; i++) {
		std::cout << arr[i] << " ";
	}
}



int main() {
	int arr[] = { -4,2,8,9,0,1,2,3,-4,2 };
	printLongest(arr, 9);
	return 0;
}