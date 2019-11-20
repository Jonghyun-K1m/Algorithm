#include <iostream>
#include <string>
using namespace std;
void fac(int num,int sum) {
	if (num == 1) {
		cout << sum;
		return;
	}
	
	sum = sum * (num);
	num = num - 1;
	fac(num, sum);
}
int main() {
	int num;
	cin >> num;
	if (num == 0) {
		cout << 1;
	}else 	fac(num, 1);

}
