#include <iostream>
#include <string>
using namespace std;
void bubble(int* arr, int num){
	int temp;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main() {

	int num;
	cin >> num;
	int* arr = new int[num];
	
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	bubble(arr, num);
	for (int i = 0; i < num; i++) {
		cout << arr[i]<<" ";
	}
	delete[] arr;
}
