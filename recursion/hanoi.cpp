#include <iostream>
#include <string>
using namespace std;
void dohanoi(int num);
void r_dohanoi(int num, string from, string mid, string to);

void dohanoi(int num) {
	r_dohanoi(num, "A", "B", "C");
}
void r_dohanoi(int num, string from, string mid, string to) {
	if (num == 1) {
		cout << "move from" << from << "to" << to << endl;
		return;
	}
	r_dohanoi(num - 1, from, to, mid);
	cout << "move from" << from << "to" << to << endl;
	r_dohanoi(num - 1, mid, from, to);
	return;
}

int main() {
	
	int to = 3;
	dohanoi(to);
}
