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
	
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i;
		*/
	int size = 4;
	for (int i = 0; i < 5; i++) {
			vector<int> a(size);

			v.push_back(a);
	}
	for (auto& j : v) {
		for (auto& k : j)
			cout << k;
		cout << endl;
	}
	for (int i = 0; i < 5; i++) {
		string n = "in";
		vector<string> a(i);
		a.push_back(n);
		tc.push_back(a);
	}
	/*string a;
	a = "sd";
	vector<string> k;
	k.push_back(a);*/
	for (auto& j : tc) {
		for (auto& k : j)
			cout << k;
	}

}
