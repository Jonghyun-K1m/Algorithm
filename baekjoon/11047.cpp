#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {

	int num, k;
	cin >> num>> k;
	int i = 0,result=0,temp;
	int arr[10] = { 0 };
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+10,greater<int>());

	while (true) {
		if (i == num)break;
		if (k / arr[i] < 1) {
			i++;
		}
		else {
			temp = k / arr[i];
			k = k- temp * arr[i];
			result = result + temp;
		}
		
	}
	cout << result;
}
