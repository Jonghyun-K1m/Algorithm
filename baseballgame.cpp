#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string randCreate() {
	srand((unsigned int)time(NULL));
	string c_num = "";
	cout << endl;
	for (int i = 0; i < 3; i++) {
		int num = rand() % 10;
		c_num = c_num + to_string(num);
	}
	return c_num;
}

int checkInput(string c_num,string input) {
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (c_num.at(i) == input.at(j)) {
				if(i==j)strike++;
				else ball++;
			}
			

		}
		
	}
	cout << "strike"<<strike << "ball"<<ball << endl;
	return strike;
}

int main() {

	string c_num = randCreate();
	string input;
	int st=0;
	while (st<3) {
		cout << "input 3 num ::";
		cin >> input;
		st=checkInput(c_num, input);
		
	}
}
