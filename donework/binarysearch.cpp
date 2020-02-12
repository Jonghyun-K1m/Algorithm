#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <array>
using namespace std;


int main() {

	int *arr, n, temp, val;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
//cout << "검색수입력>>";
	cin >> val;
	int pl, pr, pc;
	int bc = 0, wc = 0;
	pl = 0, pr = n, pc = n / 2;
	for (pl; pl < pr; pl++) {
		bc++;
		if (val == arr[pc]) {
			cout << "완료";
			break;
		}
		if (val > arr[pc]) {
			pl = pc;
			pc = (pl + pr) / 2;
		}
		else {
			pr = pc;
			pc = (pl + pr) / 2;
		}
	}
	for (int i = 0; i < arr[i]; i++) {
		if (arr[i] == val)break;
		wc++;
	}
	cout << bc << wc;
	delete[] arr;
}
