#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
using namespace std;
int main() {

	vector<vector<int>> v;
	vector<vector<string>> tc;
	/*v.push_back(10);
	

	/*int size = 4;
	for (int i = 0; i < 5; i++) {
			vector<int> a(size);
			v.push_back(a);
	}
	for (auto& j : v) {
		for (auto& k : j)
			cout << k;
		cout << endl;
	}*/
	int size = 4;
	vector<string> input = { "inc","kor" };
	
	for (int i = 0; i < 5; i++) {
		string n = "in";	
		//vector<string> a(size);
		//a.push_back(n);
		tc.push_back(input);
	} 

	for (auto& j : tc) {	
		for (auto& k : j)
			cout << k;
		cout << endl;
	}

}
