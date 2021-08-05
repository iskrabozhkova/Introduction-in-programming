#include <iostream>

bool checkSymbol(char c1, char c2) {
	if (c1 >= 'a' && c1 <= 'z' && c2 >= 'A' && c2 <= 'Z' && 'Z' - c2 < 'z' - c1 ){
			return true;
	}
	else {
		return false;
	}

}





int main() {
	//2
	/*int n;
	std::cin >> n;
	int len = n;
	int* arr = new int[n];
	int i = 0;
	while (n != 0) {
		int num;
		std::cin >> num;
		arr[i] = num;
		i++;
		n--;
	}
	int sum = 0;
	int count = 1;
	for (int j = 1; j < len; j++) {
		for (int k = j-1; k >= 0; k--) {
			sum += arr[k];
		}
		if (sum == arr[j]) {
			count++;
		}
		sum = 0;
	}
	std::cout << count;
	delete[] arr;*/

	//3
	int n;
	std::cin >> n;
	int len = n;
	double* arr = new double[n];
	int i = 0;

	while (n != 0) {
		double num;
		std::cin >> num;
		arr[i] = num;
		i++;
		n--;
	}

	//chetni
	int minX = arr[0];
	int maxX = arr[0];
	for (int i = 0; i < len; i+=2) {
		if (arr[i] < minX) {
			minX = arr[i];
		}
		if (arr[i] > maxX) {
			maxX = arr[i];
		}
	}
	double difference_X = maxX - minX;

	//nechetni
	int minY = arr[1];
	int maxY = arr[1];
	for (int i = 1; i < len; i += 2) {
		if (arr[i] < minY) {
			minY = arr[i];
		}
		if (arr[i] > maxY) {
			maxY = arr[i];
		}
	}
	double difference_Y = maxY - minY;
	double area = 0;
	if (difference_X >= difference_Y) {
		area = difference_X * difference_X;
	}
	else {
		area = difference_Y * difference_Y;
	}
	std::cout << area;
	return 0;
}